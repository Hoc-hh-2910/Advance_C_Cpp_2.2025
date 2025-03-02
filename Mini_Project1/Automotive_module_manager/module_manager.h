#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


#define MODULLE_NAME_MAX 50

typedef uint8_t ModuleStatus;
typedef uint8_t ModuleID;
typedef uint8_t ModuleAccess;
typedef uint8_t ModuleControl;

typedef struct Module
{
    ModuleID ID :8;
    char name[MODULLE_NAME_MAX];
    ModuleAccess access :2;
    ModuleControl control :2;
    ModuleStatus status :3;
};

typedef struct ModuleManager
{
    struct Module *modules;
    size_t numModules;
    size_t maxModules;
    jmp_buf error_Handler;
};

void initModuleManager(struct ModuleManager *manager, size_t maxModules);
void addModule(struct ModuleManager *manager, ModuleID ID, const char *name, ModuleStatus status, ModuleAccess access, ModuleControl control);
void removeModule(struct ModuleManager *manager, ModuleID ID);
void listModules(const struct ModuleManager *manager);
void freeModuleManager(struct ModuleManager *manager);

#endif // MODULE_MANAGER_H