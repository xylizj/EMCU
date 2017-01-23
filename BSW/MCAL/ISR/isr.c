#include "MPC5643L.h"
#include "isr.h"
#include "Gpt.h"//"stm.h"
#include "foc.h"
#include "AD2S1210.h"
#include "Adc.h"
#include "SchM.h"
#include "FlexPWM.h"


#define PHASE_CUR_RAW_DELTA_MAX 10
#define POS_RAW_DELTA_MAX 10

volatile uint16_t PhaseCurRawULast;
volatile uint16_t PhaseCurRawVLast;
volatile uint16_t PhaseCurRawWLast;

volatile uint16_t PhaseCurRawLast[3];
volatile uint16_t PhaseCurRawCurrent[3];

uint32_t   PosLast;

uint32_t angle_a;



#ifdef MOTOR0
uint32_t angle_pos_zero = 24320;//20336;//19627;//motor 0
#define SID_m_ct_CurPhaseU_Ref 1730	
//#define SID_m_ct_CurPhaseV_Ref 2047
#define SID_m_ct_CurPhaseW_Ref 1776
#endif

#ifdef MOTOR1
uint32_t angle_pos_zero = 11306;//motor 1,new
#define SID_m_ct_CurPhaseU_Ref 2020
#define SID_m_ct_CurPhaseV_Ref 2045
#define SID_m_ct_CurPhaseW_Ref 2074
#endif

uint32_t angle_b;
int32_t angle_c;

extern SInt32 SID_m_i_CurPhaseU;
extern SInt32 SID_m_i_CurPhaseW;

static uint8_t phase_not_first_time = 1;
static uint8_t pos_not_first_time = 1;

extern uint8_t PhaseDrvEnabled_Flag;
extern uint8_t PhaseDrvEnable_FirstTime_Flag;
uint8_t  DANGER_FLAG = 0;

uint16_t SID_m_ct_CurPhaseURaw_Log;
uint16_t SID_m_ct_CurPhaseWRaw_Log;

static inline
void AcquirePhaseCur(void)
{
	SID_m_ct_CurPhaseURaw = (uint16_t)(RawVoltagesTable_FIFO3[0] & ADC_RESULT_MASK);
	SID_m_ct_CurPhaseWRaw = (uint16_t)(RawVoltagesTable_FIFO3[1] & ADC_RESULT_MASK);

	//disable Phase Drv in case of current exceed limit 
	/*if(PhaseDrvEnabled_Flag)
	{		
		if(SID_m_ct_CurPhaseURaw>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseU_Ref)
		   || SID_m_ct_CurPhaseU_Ref>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseURaw))
		{
			SIU.GPDO[CTL_PHASE_DRV_ENABLE_PAD_NUM].R=0;//三相驱动失能
			DANGER_FLAG = 1;//SID_m_ct_CurPhaseURaw_Log = SID_m_ct_CurPhaseURaw;	
		}
		if(SID_m_ct_CurPhaseWRaw>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseW_Ref)
		   || SID_m_ct_CurPhaseW_Ref>(CUR_PHASE_RAW_DELTA_THROLD+SID_m_ct_CurPhaseWRaw))
		{
			SIU.GPDO[CTL_PHASE_DRV_ENABLE_PAD_NUM].R=0;//三相驱动失能	
			DANGER_FLAG = 1;//SID_m_ct_CurPhaseWRaw_Log = SID_m_ct_CurPhaseWRaw;
		}
	}*/
	
	//Phase current normalization//
	SID_m_i_CurPhaseU = (SInt32)(((SInt16)(SID_m_ct_CurPhaseURaw-SID_m_ct_CurPhaseU_Ref))<<20);//*1048576
    SID_m_i_CurPhaseW = (SInt32)(((SInt16)(SID_m_ct_CurPhaseWRaw-SID_m_ct_CurPhaseW_Ref))<<20);
}


static inline
void UpdatePWM_MDRV(void)
{
    stc_hMDRV_pwmAbc.s16sub0   &= 0xFFFE;
	stc_hMDRV_pwmAbc.s16sub1   &= 0xFFFE;
	stc_hMDRV_pwmAbc.s16sub2   &= 0xFFFE;

	FLEXPWM_0.MCTRL.B.CLOK |= 1;
	FLEXPWM_0.SUB[0].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub0);
	FLEXPWM_0.SUB[0].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub0);					
	FLEXPWM_0.SUB[1].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub1);
	FLEXPWM_0.SUB[1].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub1);					
	FLEXPWM_0.SUB[2].VAL[2].R = (int16_t)-(stc_hMDRV_pwmAbc.s16sub2);
	FLEXPWM_0.SUB[2].VAL[3].R = (int16_t)(stc_hMDRV_pwmAbc.s16sub2);
	FLEXPWM_0.MCTRL.B.LDOK |= 0b1;
}

uint32 Isr_CurrentCnt1,Isr_CurrentCnt2;
uint32 Isr_CurExcTime;

void eTimer_1_TC5IR_Isr(void) 
{
	ETIMER_1.CHANNEL[5].STS.B.TCF=1; 

	Isr_CurrentCnt1 = Gpt_GetCurrentCnt();
	
	AcquirePhaseCur();	
	Enc_SpdMeas();//20161128 xyl add
	EncodePosGet();
		
	focFastLoop();
	UpdatePWM_MDRV();
	
	Isr_CurrentCnt2 = Gpt_GetCurrentCnt();
	Isr_CurExcTime = Isr_CurrentCnt2 - Isr_CurrentCnt1;
}
