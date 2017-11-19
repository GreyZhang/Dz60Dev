#ifndef TASK_H
#define TASK_H

#include "gtypes.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */


extern void Task10ms(void);
extern void Task20ms(void);
extern void Task100ms(void);
extern void TaskInit(void);


#endif

