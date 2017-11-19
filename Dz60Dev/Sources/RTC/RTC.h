#ifndef RTC_H
#define RTC_H

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "mc9s08dz60.h"
#include "RTC_Data.h"
#include "gtypes.h"
#include "Task.h"

extern void RTC_initialize(void);
extern void interrupt VectorNumber_Vrtc RTC_ISR(void);


#endif

