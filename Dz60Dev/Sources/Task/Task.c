#include "Task.h"

#define LED PTAD_PTAD0
#define LED_dir PTADD_PTADD0

void TaskInit(void)
{
	LED_dir = 1;
	LED = 0;
}



void Task10ms(void)
{

}

void Task20ms(void)
{

}

void Task100ms(void)
{
	static uint8_T counter = 0U;

	counter += 1U;

	if(counter == 10U)
	{
		LED = !LED;
		counter = 0U;
	}
}

