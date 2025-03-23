#ifndef _Linked_list_h
#define _Linked_list_h

#include <stdio.h>
#include <stdlib.h>

// Tạo struct node cho Linked List
typedef struct node
{
    int value;
    struct node* next;
}node;

/**
 * @brief   Khởi tạo Node.
 * @param   value   Thông tin của node.
 * @return  node   Trả về node mới được khởi tạo.
 */
node* createNode(int value);

/**
 * @brief   Thêm phần tử vào cuối danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void push_back(node** array, int value);

/**
 * @brief   Xóa phần tử cuối cùng khỏi danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void pop_back(node** array);

/**
 * @brief   Lấy giá trị của phần tử tại vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần lấy giá trị.
 * @return  int
 */
int get(node* array, int pos);

/**
 * @brief   Thêm phần tử vào đầu danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void push_front(node** array, int value);

/**
 * @brief   Xóa phần tử đầu tiên khỏi danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void pop_front(node** array);

/**
 * @brief   Lấy số lượng phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  int
 */
int size(node* array);

/**
 * @brief   Kiểm tra danh sách liên kết có rỗng hay không.
 * @param   array   Danh sách liên kết.
 * @return  int
 */
int empty(node* array);

/**
 * @brief   Hiển thị các phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void display(node* array);

/**
 * @brief   Xóa toàn bộ phần tử trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void clear(node** array);

/**
 * @brief   Thêm phần tử vào vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần thêm phần tử.
 * @param   value   Giá trị cần thêm vào danh sách liên kết.
 * @return  void
 */
void insert(node** array, int pos, int value);

/**
 * @brief   Lấy giá trị Node đầu tiên trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void front(node* array);

/**
 * @brief   Lấy giá trị Node cuối cùng trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @return  void
 */
void back(node* array);

/**
 * @brief   Xóa phần tử tại vị trí pos trong danh sách liên kết.
 * @param   array   Danh sách liên kết.
 * @param   pos     Vị trí cần xóa phần tử.
 * @return  void
 */
void erase(node** array, int pos);

#endif
