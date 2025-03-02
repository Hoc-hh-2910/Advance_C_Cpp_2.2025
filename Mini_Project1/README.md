# Mini Project 1 - Description

**Chương trình sẽ có cấu trúc như sau**

```
Automotive_Module_Manager/

├── main.c              // Chương trình chính
├── module_manager.c    // Xử lý danh sách module
├── module_manager.h    // Header file của module manager
├── bitmask_utils.c     // Hàm hỗ trợ bitmask
├── bitmask_utils.h     // Header file cho bitmask
├── function_handler.c  // Xử lý con trỏ hàm
├── function_handler.h  // Header file của function handler

Handler
├── error_handler.c     // Xử lý lỗi
├── error_handler.h     // Header file xử lý lỗi
```

Ta sẽ thực hiện chương trình như trong flow sau:

![Image](D:\Github\Advance_C_Cpp_2.2025\Mini_Project1\Flow_Chart_MiniProject.drawio.png)

**Khởi tạo Module Manager**

Ta sẽ thực hiện định nghĩa các biến và các hàm cần dùng trong file ``module_manager.h`` và ``module_manager.c``

```C
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
```

Ta có thể sử dụng BitMask để thực hiện SET ON/OFF cho các Module. Chương trình được định nghĩa trong ``bitmask_ultis.h`` và ``bitmask_ultis.c``

```C
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
```

``Function_handler.h`` và ``Function_handler.c`` sẽ định nghĩa các hàm được sử dụng để thay đổi module và sử dụng chúng cho một con trỏ hàm

```C
void StatusON_Module(const struct ModuleManager *manager, ModuleID ID);
void StatusError_Module(const struct ModuleManager *manager, ModuleID ID);
void StatusWarning_Module(const struct ModuleManager *manager, ModuleID ID);
```

Với các lỗi có thể xảy ra thì ta có ``error_handler.h`` và ``error_handler.c`` để đưa các Module về trạng thái an toàn

```C
void Error_Handler(const struct ModuleManager *manager);
```

