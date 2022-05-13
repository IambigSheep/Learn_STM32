#include "stm32f4xx.h"
#include "bsp_led.h"


void delay(uint32_t num)
{
	for(;num != 0;num--);
}

int main(void)
{
	LED_GPIO_Config();
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_6);
		delay(0x0ffffff);
		GPIO_SetBits(GPIOF,GPIO_Pin_6);
		delay(0x0ffffff);
		GPIO_ResetBits(GPIOF,GPIO_Pin_7);
		delay(0x0ffffff);
		GPIO_SetBits(GPIOF,GPIO_Pin_7);
		delay(0x0ffffff);
		GPIO_ResetBits(GPIOF,GPIO_Pin_8);
		delay(0x0ffffff);
		GPIO_SetBits(GPIOF,GPIO_Pin_8);
		delay(0x0ffffff);
	}
}
