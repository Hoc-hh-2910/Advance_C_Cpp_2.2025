#include "bitmask_ultis.h"
#include "D:\Github\Advance_C_Cpp_2.2025\Mini_Project1\Handler\error_hander.h"
#include "function_handler.h"
#include "module_manager.h"

int main()
{
    struct ModuleManager manager;

    printf("Initializing Module Manager\n");
    initModuleManager(&manager, 5);

    printf("Adding Modules\n");
    addModule(&manager, 1, "Module1", STATUS_ON, ACCESS_ON, AUTO);
    addModule(&manager, 2, "Module2", STATUS_ON, ACCESS_ON, AUTO);
    addModule(&manager, 3, "Module3", STATUS_ON, ACCESS_ON, AUTO);
    addModule(&manager, 4, "Module4", STATUS_ON, ACCESS_ON, AUTO);
    addModule(&manager, 5, "Module5", STATUS_ON, ACCESS_ON, AUTO);

    printf("Listing Modules\n");
    listModules(&manager);

    printf("Setting Module Status\n");
    StatusON_Module(&manager, 1);
    StatusError_Module(&manager, 2);
    StatusWarning_Module(&manager, 3);

    listModules(&manager);

    printf("Removing Modules\n");
    removeModule(&manager, 1);
    removeModule(&manager, 2);
    removeModule(&manager, 3);

    listModules(&manager);

    Error_Handler(&manager);

    freeModuleManager(&manager);

    return 0;
}

