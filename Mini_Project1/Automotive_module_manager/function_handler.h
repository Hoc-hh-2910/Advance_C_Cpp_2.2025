#include <stdio.h>
#include <stdlib.h>
#include "module_manager.h"
#include "bitmask_ultis.h"

void StatusON_Module(const struct ModuleManager *manager, ModuleID ID);
void StatusError_Module(const struct ModuleManager *manager, ModuleID ID);
void StatusWarning_Module(const struct ModuleManager *manager, ModuleID ID);