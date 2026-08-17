#ifndef TIMSCHEDULER_H
#define TIMSCHEDULER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "struct_typedef.h"

typedef struct{
    void (*taskFunc)(void const *argument);
    uint32_t periodMs;
    uint32_t lastRunTime;
    vuint8_t flagIRQ;
}ScheduleTask;

#ifdef __cplusplus
}
#endif

#endif
