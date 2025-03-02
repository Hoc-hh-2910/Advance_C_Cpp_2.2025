#include "bitmask_ultis.h"

void SetBit(ModuleStatus *var, uint8_t STATUS)
{
    *var |= STATUS;
    return;
}

void ClearBit(ModuleStatus *var, uint8_t STATUS)
{

    *var &= ~STATUS;
    return;
}
