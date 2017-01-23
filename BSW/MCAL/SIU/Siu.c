/************************************************************************/
/* File Name:      Siu.c
/* Description:    
/* Comments:       
/*
/* Version     Date           Author           Remark
/* -------  ----------   --------------   ------------------------------      
/*
/************************************************************************/




#include "Siu.h"
 
 
/************************************************************************/
/* Desc: configure in and output pins									*/
/************************************************************************/
void ConfigureSIU(void) 
{
	SIU.PCR[CTL_PHASE_DRV_ENABLE_PAD_NUM].B.OBE = 1;//��������ʹ�ܣ��ߵ�ƽ��Ч
	SIU.GPDO[CTL_PHASE_DRV_ENABLE_PAD_NUM].R=0;
	SIU.PCR[CTL_PHASE_DRV_FAULT_RESET_PAD_NUM].B.OBE = 1;//����Ԥ�����ϸ�λ��Ĭ������͵�ƽ

}



void Siu_Out(uint16 ch,boolean val)
{
	if (val == TRUE)
	{
		SET_STATUS(ch);	
	}
	else
	{
		RESET_STATUS(ch);		
	}
}

boolean Siu_ReadDI(uint16 ch)
{
	boolean retVal;
	
	retVal = (boolean)(GET_STATUS(ch));
	
	return (retVal);	
}

