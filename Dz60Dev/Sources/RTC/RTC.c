#include "RTC.h"

/*
	By Grey, first written at night in 2017-10-26.
*/
void RTC_initialize(void)
{
	/**
	 *  V0.1.0
	 *  2017/11/19 Grey
	 *  Change the source of RTC to ERCLK.
	 * */
	RTCSC_RTCLKS = 0b01;

	/* Real-time interrupt requests are enabled. */
	RTCSC_RTIE = 1;

	/**
	 * V0.1.0
	 * 2017/11/19 Grey
	 * Number 14 will set a counter for 10^5. This would be 0.025s timer setting for a 4MHz clock.
	 * Number 12 will set a counter for 5ms when using a 4MHz clock.
	 * */
	RTCSC_RTCPS = 12;

}

void interrupt VectorNumber_Vrtc RTC_ISR(void)
{
	/* a counter for 5ms */
	static uint8_T counter5Ms = 0;

	/* Clear the interrupt flag */
	RTCSC_RTIF = 1;
	
	counter5Ms += 1;

	if(counter5Ms == 2)
	{
		task_counter += 1U;
		Task10ms();
		counter5Ms = 0;
	}
	else
	{
		/* no code */
	}

	if(task_counter % 2U == 1U)
	{
		Task20ms();
	}

	if(task_counter == 10U)
	{
		Task100ms();
		task_counter = 0U;
	}
}


