/*******************************************************************************
*
*  FILE
*     Ioa.c
*
*  DESCRIPTION
*     Source File for IO abstraction   
*      
*       
*  COPYRIGHT
*     
*     All rights reserved.
*
*  AUTHOR
*   
*
*  VERSION
*    1.0.0
*
*******************************************************************************/

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Ioa.h"
//#include "Dem.h"


/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/
uint8_t SID_m_swt_PhaDrvFaultRaw;

uint8_t SID_m_swt_IGNRaw;
uint8_t SID_m_swt_ENRaw;
uint8_t SID_m_swt_RsolvDOSRaw;
uint8_t SID_m_swt_RsolvLOTRaw;



void Ioa_Init(void)
{
	//Ioa_GPIOInit();
	SIU.GPDO[O_S_SysPWRCtrl_PAD_NUM].R=1;
	SIU.PCR[O_S_SysPWRCtrl_PAD_NUM].B.OBE = 1;

	SIU.PCR[CTL_PHASE_DRV_ENABLE_PAD_NUM].B.OBE = 1;//三相驱动使能，高电平有效
	Ioa_PhaseDrvDisable();
	
	SIU.PCR[Relay_Ctrl_PAD_NUM].B.OBE = 1;
	
	
	SIU.PCR[Buzzer_Ctrl_PAD_NUM].B.OBE = 1;
	RESET_STATUS(Relay_Ctrl_PAD_NUM);	
}


_STATIC_ void Ioa_ReadSwtValue(void)
{
  SID_m_swt_PhaDrvFaultRaw = !GET_STATUS(I_S_PHASEFLT_PAD_NUM);
  SID_m_swt_ExcDrvFaultRaw = !GET_STATUS(I_S_EXCFLT_PAD_NUM);    	   
}


void Ioa_Input(void)
{
	//Ioa_ReadSwtValue();
}


void Ioa_PhaseDrvEnable(void)
{
	SET_STATUS(CTL_PHASE_DRV_ENABLE_PAD_NUM);
}

void Ioa_PhaseDrvDisable(void)
{
	RESET_STATUS(CTL_PHASE_DRV_ENABLE_PAD_NUM);
}


void Ioa_PhaseDrvFaultReset(void)
{
	SIU.GPDO[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].R=1;
	delay_us(25);
	SIU.GPDO[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].R=0;
}

extern uint16_t SID_m_ct_VBATRaw;
extern uint16_t SID_m_ct_VBAT2Raw;

uint8_t PhaseDrvEnable_FirstTime_Flag = 0;
uint8_t PhaseDrvEnabled_Flag = 0;
//x*3300/4096*51 >= 40000
void Ioa_Output(void)
{
	static uint8_t lcnt = 0;
	static uint8_t lcnt2 = 0;
	static uint8_t Relay_On_Flag = 0;
	
	RESET_STATUS(Buzzer_Ctrl_PAD_NUM);

	if(!Relay_On_Flag)
	{		
		if(SID_m_ct_VBATRaw >= (974) && SID_m_ct_VBAT2Raw >= (974))
		{
			if(SID_m_ct_VBATRaw > (SID_m_ct_VBAT2Raw*4/5))
			{
				SET_STATUS(Relay_Ctrl_PAD_NUM);
				Relay_On_Flag = 1;
			}
		}
	}
	
	if(Relay_On_Flag && !PhaseDrvEnabled_Flag)
	{
		lcnt ++;
		if(lcnt > 5)
		{
			PhaseDrvEnable_FirstTime_Flag = 1;	
		}
		
		if(PhaseDrvEnable_FirstTime_Flag)
		{
			Ioa_PhaseDrvEnable();
			
			lcnt2 ++;
			if(lcnt2 > 2)
			{
				//eTimer0_Encode_Init();
				//ConfigureDMA11_eTimer0Ch1();
				PhaseDrvEnabled_Flag = 1;	
			}			
		}	
	}		
}
