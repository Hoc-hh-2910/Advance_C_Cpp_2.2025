#include "error_hander.h"

void Error_Handler(const struct ModuleManager *manager)
{
    if (setjmp(manager->error_Handler) == 1)
    {
        printf("Error in module manager initialization.\n");
        return;
    }
}