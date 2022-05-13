#include "bsp_key.h"

void KEY_GPIO_Config(void)	//��ʼ������
{

	
	/* �����ĸ������ʺ��������� */
	/* ��һ����������ʱ�� */
	RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
	/* �ڶ����������ʼ���ṹ�� */
	GPIO_InitTypeDef GPIO_InitStruct;
	/* �����������ó�ʼ���ṹ��ĳ�Ա */
	GPIO_InitStruct.GPIO_Pin = KEY1_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/* ���Ĳ������ó�ʼ�������������úõĽṹ�����д��Ĵ��� */
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = KEY2_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStruct);
}

uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)	//���������ж� ���� KEY_ONΪ����
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
	{
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}
