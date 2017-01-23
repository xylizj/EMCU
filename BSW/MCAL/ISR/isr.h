#ifndef __ISR_H_
#define __ISR_H_


//(372*3300/4096)*5/3=0.5V
#define CUR_PHASE_RAW_DELTA_THROLD 600



extern void eTimer_1_TC5IR_Isr(void);


extern  uint8_t  DANGER_FLAG;
extern  int32_t angle_c;







#endif
