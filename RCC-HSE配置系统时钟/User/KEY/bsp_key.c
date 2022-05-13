#include "bsp_key.h"

void KEY_GPIO_Config(void)	//初始化按键
{

	
	/* 以下四个步骤适合所有外设 */
	/* 第一步：开外设时钟 */
	RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
	/* 第二部：定义初始化结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;
	/* 第三步：配置初始化结构体的成员 */
	GPIO_InitStruct.GPIO_Pin = KEY1_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/* 第四步：调用初始化函数，把配置好的结构体参数写入寄存器 */
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = KEY2_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStruct);
}

uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)	//按键按下判断 返回 KEY_ON为按下
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
	{
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}
