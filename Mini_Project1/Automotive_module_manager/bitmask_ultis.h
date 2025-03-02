#ifndef _BITMASK_ULTIS_H
#define _BITMASK_ULTIS_H

#include <stdio.h>
#include "module_manager.h"

#define STATUS_ON       (1 << 0)
#define STATUS_ERROR    (1 << 1)
#define STATUS_WARNING  (1 << 2)

#define ACCESS_ON       (1 << 0)
#define ACCESS_OFF      (1 << 1)

#define AUTO            (1 << 0)
#define MANUAL          (1 << 1)

#define CHECK_BIT(var, STATUS) ((var) & (STATUS))

void SetBit(ModuleStatus *var, uint8_t STATUS);
void ClearBit(ModuleStatus *var, uint8_t STATUS);
// void displayBits(int var);


#endif