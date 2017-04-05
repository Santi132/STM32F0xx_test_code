//Setting high and low a pin on the chip

#include "stm32f0xx.h"
#include "C:\Users\Santiago\CoIDE\workspace\LCD_PIN_test\components\coocox-master\STM32F030x8_CUBELIB\source\stm32f0xx_hal_conf.h"
int main(void)
{
	//Registers that we are going to need to manipulate the pin
	//ModeR, OtypeR, OspeedR,PUPDR, RCC

	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER3_0;
	GPIOB->MODER &= ~(GPIO_MODER_MODER3_1);
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_3);
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3_1;
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR3);

    while(1)
    {
    	//Set the pin high
    	//GPIOB->BSRR |= GPIO_BSRR_BS_3;
    	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
    	//Wait
    	for(int i = 0; i < 500000;i++);

    	//GPIOB->BRR |= GPIO_BRR_BR_3;
    	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);

    	//Wait
    	for(int i = 0; i < 500000;i++);
    }
}
