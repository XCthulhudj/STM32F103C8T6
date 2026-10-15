#ifndef APPLAYER_INIT_H
#define APPLAYER_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "struct_typedef.h"

typedef struct{
    uint8_t boxFlag[10];
}topLayer_t;

extern volatile topLayer_t mainStream;

void appLayer_init(void);
void taskScheduler_running(void);

#ifdef __cplusplus
}
#endif

#endif
