#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *item;  // mảng lưu trữ giá trị các phần tử
    int size;   // số lượng phần tử tối đa có thể đưa vào
    int front;  // chỉ số của phần tử đầu hàng đợi
    int rear;   // chỉ số của phần tử cuối hàng đợi
} Queue;

/**
 * @brief   Khởi tạo Hàng đợi.
 * @param   queue   Thông tin của queue hiện tại.
 * @param   size    Số lượng phần tử tối đa của Queue.
 * @return  void
 */
void initialize(Queue *queue, int size);

/**
 * @brief   Kiểm tra Queue có rỗng hay không.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  bool
 */
bool isEmpty(Queue queue);

/**
 * @brief   Kiểm tra Queue có đầy hay không.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  bool
 */
bool isFull(Queue queue);

/**
 * @brief   Thêm phần tử vào cuối hàng đợi.
 * @param   queue   Thông tin của queue hiện tại.
 * @param   data    Giá trị cần thêm vào queue.
 * @return  void
 */
void enqueue(Queue *queue, int data);

/**
 * @brief   Xóa phần tử đầu hàng đợi và trả giá trị.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  int    Giá trị của phần tử bị xóa.
 */
int dequeue(Queue *queue);

/**
 * @brief   Đọc giá trị tại đầu hàng đợi.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  int    Giá trị của phần tử ở đầu queue.
 */
void display(Queue queue);

/**
 * @brief   Đọc giá trị tại đầu hàng đợi.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  int    Giá trị của phần tử ở đầu queue.
 */
int front(Queue queue);

/**
 * @brief   Đọc giá trị tại cuối hàng đợi.
 * @param   queue   Thông tin của queue hiện tại.
 * @return  int    Giá trị của phần tử ở cuối queue.
 */
int rear(Queue queue);
