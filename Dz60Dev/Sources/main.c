#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SysClk.h"
#include "RTC.h"

#define LED_dir PTADD_PTADD0

/*
	delay 2000 clock.
*/
void delay(void) 
{
	unsigned int i;
	for(i = 0;i < 500;i++)
	{
		__RESET_WATCHDOG();
	}
}

void MyDelay(void)
{
	unsigned int i;
	/* 4M clock */
	for(i = 0;i < 1000;i++)
	{
		delay();
	}
}

void TaskInit(void);

void main(void) 
{
	DisableInterrupts;
	SysClkInit();
	LED_dir = 1;
	RTC_initialize();
	TaskInit();
	/* close watchdog */
	SOPT1 = 0;
	EnableInterrupts; /* enable interrupts */

	for(;;) 
	{
	}
}

