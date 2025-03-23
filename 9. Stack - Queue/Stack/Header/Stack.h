#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *item;  // mảng lưu trữ giá trị các phần tử
    int size;   // số lượng phần tử tối đa của Stack
    int top;    // chỉ số lấy giá trị ở đỉnh Stack
} Stack;

#define STACK_EMPTY -1

/**
 * @brief   Khởi tạo Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @param   newSize Số lượng phần tử tối đa của Stack.
 * @return  void
 */
void init(Stack *stack, int newSize);


/**
 * @brief   Kiểm tra Stack có rỗng hay không.
 * @param   stack   thông tin của stack hiện tại.
 * @return  bool
 */
bool isEmpty(Stack stack);

/**
 * @brief   Kiểm tra Stack có đầy hay không.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  bool
 */
bool isFull(Stack stack);

/**
 * @brief   Thêm phần tử vào đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @param   data    Giá trị cần thêm vào stack.
 * @return  void
 */
void push(Stack *stack, int data);

/**
 * @brief   Xóa phần tử trên đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  int    Giá trị của phần tử bị xóa.
 */
int pop(Stack *stack);

/**
 * @brief   Đọc giá trị tại đỉnh Stack.
 * @param   stack   Thông tin của stack hiện tại.
 * @return  int    Giá trị của phần tử ở đỉnh stack.
 */
int top(Stack stack);


#endif // _STACK_H
