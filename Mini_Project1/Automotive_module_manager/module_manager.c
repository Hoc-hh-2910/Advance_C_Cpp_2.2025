#include <stdio.h>
#include <stdlib.h>
#include "module_manager.h"


void initModuleManager(struct ModuleManager *manager, size_t maxModules)
{
    if(setjmp(manager->error_Handler) != 0)
    {
        printf("Error in module manager initialization.\n");
        return;
    }
    manager->modules = (struct Module *)malloc(maxModules * sizeof(struct Module));
    if(manager->modules == NULL)
    {
        longjmp(manager->error_Handler, 1);
    }

    manager->numModules = 0;
    manager->maxModules = maxModules;
}

void addModule(struct ModuleManager *manager, ModuleID ID, const char *name, ModuleStatus status, ModuleAccess access, ModuleControl control)
{
    if(setjmp(manager->error_Handler) != 0)
    {
        printf("Error in adding module.\n");
        return;
    }

    if(manager->numModules >= manager->maxModules)
    {
        longjmp(manager->error_Handler, 1);
    }
    manager->modules[manager->numModules].ID = ID;
    snprintf(manager->modules[manager->numModules].name, MODULLE_NAME_MAX, "%s", name);
    manager->modules[manager->numModules].access = access;
    manager->modules[manager->numModules].control = control;
    manager->modules[manager->numModules].status = status;
    manager->numModules++;
}

void removeModule(struct ModuleManager *manager, ModuleID ID)
{
    for (size_t i = 0; i < manager->numModules; i++)
    {
        if (manager->modules[i].ID == ID)
        {
            for (size_t j = i; j < manager->numModules - 1; j++)
            {
                manager->modules[j] = manager->modules[j + 1];
            }
            manager->numModules--;
            return;
        }
    }
    printf("Module not found.\n");
}

void listModules(const struct ModuleManager *manager)
{
    printf("Modules: \n");
    for (size_t i = 0; i < manager->numModules; i++)
    {
        printf("ID: %d\n", manager->modules[i].ID);
        printf("Name: %s\n", manager->modules[i].name);
        printf("Access: %d\n", manager->modules[i].access);
        printf("Control: %d\n", manager->modules[i].control);
        printf("Status: %d\n", manager->modules[i].status);
        printf("\n");
    }
}

void freeModuleManager(struct ModuleManager *manager)
{
    free(manager->modules);
    manager->numModules = 0;
    manager->maxModules = 0;
}