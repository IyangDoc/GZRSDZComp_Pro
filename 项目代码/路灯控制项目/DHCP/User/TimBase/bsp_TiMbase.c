/******************************************************************************
* @file    bsp_TimBase.c
* @author  fire
* @version V1.0
* @date    2013-xx-xx
* @brief   TIM2 1ms ��ʱӦ��bsp
*******************************************************************************/ 
#include "bsp_TiMbase.h" 


//TIM2�ж����ȼ�����
void TIM2_NVIC_Configuration(void)
{
	NVIC_InitTypeDef	NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  

	NVIC_InitStructure.NVIC_IRQChannel 					 = TIM2_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority 		 = 2;	
	NVIC_InitStructure.NVIC_IRQChannelCmd 				 = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


/****************************************************************************************
	* TIM_Period / Auto Reload Register(ARR) = 1000   TIM_Prescaler--71 
	* �ж�����Ϊ = 1/(72MHZ /72) * 1000 = 1ms
	*
	* TIMxCLK/CK_PSC --> TIMxCNT --> TIM_Period(ARR) --> �ж� ��TIMxCNT����Ϊ0���¼��� 
*****************************************************************************************/
void TIM2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);			//����TIM2��ʱ��Ϊ72MHz
	
	TIM_TimeBaseStructure.TIM_Period		= 1000;					//�Զ���װ�ؼĴ������ڵ�ֵ(����ֵ)
	TIM_TimeBaseStructure.TIM_Prescaler		= 71;					//ʱ��Ԥ��Ƶ��Ϊ72
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;			//���ⲿʱ�ӽ��в�����ʱ�ӷ�Ƶ,����û���õ� 
	TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;	//���ϼ��� 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);					//����ָ��������ʼ��TIM2

	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM2, ENABLE);																		

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE);			//�ȹرյȴ�ʹ��    
}







