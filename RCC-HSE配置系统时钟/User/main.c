#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_key.h"


void delay(uint32_t num)
{
	for(;num != 0;num--);
}

int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	while(1)
	{
		if(KEY_Scan(KEY1_GPIO_PORT,KEY1_Pin) == KEY_ON)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_6);
		}
		if(KEY_Scan(KEY2_GPIO_PORT,KEY2_Pin) == KEY_ON)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_7);
		}
//		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
//		delay(0x0ffffff);
//		GPIO_SetBits(GPIOF,GPIO_Pin_6);
//		delay(0x0ffffff);
//		GPIO_ResetBits(GPIOF,GPIO_Pin_7);
//		delay(0x0ffffff);
//		GPIO_SetBits(GPIOF,GPIO_Pin_7);
//		delay(0x0ffffff);
//		GPIO_ResetBits(GPIOF,GPIO_Pin_8);
//		delay(0x0ffffff);
//		GPIO_SetBits(GPIOF,GPIO_Pin_8);
//		delay(0x0ffffff);
	}
}
