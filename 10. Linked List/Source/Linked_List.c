#include "..//Header/Linked_list.h"

/**
 * @brief   Khởi tạo Node.
 * @param   value   Thông tin của node.
 * @return  node   Trả về node mới được khởi tạo.
 */
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

/**
 * @brief   Thêm phần tử vào cuối danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

/**
 * @brief   Xóa phần tử cuối cùng khỏi danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}

/**
 * @brief   Lấy giá trị của phần tử tại vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần lấy giá trị.
 * @return  int
 */
int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

/**
 * @brief   Thêm phần tử vào đầu danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void push_front(node** array, int value)
{
    node* temp;
    temp = createNode(value);
    temp->next = *array;
    *array = temp;
}

/**
 * @brief   Xóa phần tử đầu tiên khỏi danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void pop_front(node** array)
{
    node* temp;
    temp = *array;
    *array = temp->next;
    free(temp);
}

/**
 * @brief   Lấy số lượng phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  int
 */
int size(node* array)
{
    int i = 0;
    while (array != NULL) // Kiểm tra khi tới Node cuối cùng
    {
        array = array->next;
        i++;
    }
    return i;
}

/**
 * @brief   Kiểm tra danh sách liên kết có rỗng hay không.
 * @param   array   Danh sách liên kết.
 * @return  int
 */
int empty(node* array)
{
    if (array == NULL)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief   Hiển thị các phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void display(node* array)
{
    int i = 0;

    while (array != NULL) // Kiểm tra khi tới Node cuối cùng
    {
        printf("Node %d: %d\n",i ,array->value);
        array = array->next;
        i++;
    }
    printf("\n");
}

/**
 * @brief   Xóa toàn bộ phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void clear(node** array)
{
    node* temp;
    while (*array != NULL)
    {
        temp = *array;
        *array = temp->next;
        free(temp);
    }
}

/**
 * @brief   Thêm phần tử vào vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần thêm phần tử.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void insert(node** array, int pos, int value)
{
    node* temp;
    temp = createNode(value);
    node* p = *array;
    int i = 0;

    if (pos == 0)
    {
        push_front(array, value);
    }
    else if (pos == size(*array))
    {
        push_back(array, value);
    }
    else
    {
        while (p->next != NULL && i < pos - 1)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

/**
 * @brief   Lấy giá trị Node đầu tiên trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void front(node* array)
{
    printf("Node 0: %d\n", array->value);
}

/**
 * @brief   Lấy giá trị Node cuối cùng trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void back(node* array)
{
    int i = 0;
    while (array->next != NULL)
    {
        array = array->next;
        i++;
    }
    printf("Node %d: %d\n", i, array->value);
}

/**
 * @brief   Xóa phần tử tại vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần xóa phần tử.
 * @return  void
 */
void erase(node** array, int pos)
{
    node* temp;
    node* p = *array;
    int i = 0;

    if (pos == 0)
    {
        pop_front(array);
    }
    else if (pos == size(*array) - 1)
    {
        pop_back(array);
    }
    else
    {
        while (p->next != NULL && i < pos - 1)
        {
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

int main()
{
    node* arr = NULL;

    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    display(arr);

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));

    printf("\n");

    erase(&arr, 2);
    display(arr);

	return 0;
}

