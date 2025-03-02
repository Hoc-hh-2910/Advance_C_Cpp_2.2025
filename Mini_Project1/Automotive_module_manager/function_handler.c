#include "function_handler.h"


void StatusON_Module(const struct ModuleManager *manager, ModuleID ID)
{
    for (size_t i = 0; i < manager->numModules; i++)
    {
        if (manager->modules[i].ID == ID)
        {
            manager->modules[i].status |= STATUS_ON;
            return;
        }
    }
}

void StatusError_Module(const struct ModuleManager *manager, ModuleID ID)
{
    for (size_t i = 0; i < manager->numModules; i++)
    {
        if (manager->modules[i].ID == ID)
        {
            manager->modules[i].status |= STATUS_ERROR;
            return;
        }
    }
}

void StatusWarning_Module(const struct ModuleManager *manager, ModuleID ID)
{
    for (size_t i = 0; i < manager->numModules; i++)
    {
        if (manager->modules[i].ID == ID)
        {
            manager->modules[i].status |= STATUS_WARNING;
            return;
        }
    }
}