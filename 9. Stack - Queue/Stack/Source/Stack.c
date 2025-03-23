#include "Stack.h"

/**
 * @brief   Khởi tạo Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @param   newSize Số lượng phần tử tối đa của Stack.
 * @return  void
 */
void init(Stack *stack, int newSize)
{
    stack->size = newSize;
    stack->item = (int*)malloc(newSize * sizeof(int));
    stack->top  = -1;
}

/**
 * @brief   Kiểm tra Stack có rỗng hay không.
 * @param   stack   thông tin của stack hiện tại.
 * @return  bool
 */
bool isEmpty(Stack stack)
{
    return (stack.top == -1 ? true : false);
}


/**
 * @brief   Kiểm tra Stack có đầy hay không.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  bool
 */
bool isFull(Stack stack)
{
    return (stack.top == (stack.size - 1) ? true : false);
}

/**
 * @brief   Thêm phần tử vào đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @param   data    Giá trị cần thêm vào stack.
 * @return  void
 */
void push(Stack *stack, int data)
{
    if (isFull(*stack))
    {
        printf("Stack đầy! Không thể thêm\n");
    }
    else
    {
        // stack->top++;
        // stack->item[stack->top] = data;

        stack->item[++stack->top] = data;
    }
}

/**
 * @brief   Xóa phần tử trên đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  int    Giá trị của phần tử bị xóa.
 */
int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack rỗng!\n");
        return STACK_EMPTY;
    }
    else
    {
        int val = stack->item[stack->top];
        stack->item[stack->top--] = 0;
        return val;
    }
}

/**
 * @brief   Đọc giá trị tại đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  int    Giá trị của phần tử ở đỉnh stack.
 */
int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rỗng!\n");
        return STACK_EMPTY;
    }
    else
    {
        return stack.item[stack.top];
    }
}

int main()
{
    Stack stack1;

    init(&stack1, 5);

    printf("Push process\n");
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("\n");
    printf("Display element\n");
    for(int i = 0; i < stack1.size; i++)
    {
        printf("Element: %d -> addr: %p\n", stack1.item[i], &(stack1.item[i]));
    }

    printf("\n");
    printf("Pop process\n");
    for(int i = 0; i < stack1.size; i++)
    {
        printf("Top element: %d -> Addr: %p\n", top(stack1), &(stack1.item[stack1.top]));
        pop(&stack1);
    }
    return 0;
}
