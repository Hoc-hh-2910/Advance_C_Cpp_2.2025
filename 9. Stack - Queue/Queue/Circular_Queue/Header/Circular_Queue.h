#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *items; // mảng lưu trữ giá trị các phần tử
    int size;   // kích thước của hàng đợi
    int front;  // chỉ số phần tử đầu hàng đợi
    int rear;   // chỉ số phần tử cuối hàng đợi
} Queue;

/**
 * @brief   Khởi tạo hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @param   size    Số lượng phần tử tối đa của hàng đợi.
 * @return  void
 */
void queue_Init(Queue *queue, int size);

/**
 * @brief   Kiểm tra hàng đợi có rỗng hay không.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int queue_IsEmpty(Queue queue);

/**
 * @brief   Kiểm tra hàng đợi có đầy hay không.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int queue_IsFull(Queue queue);

/**
 * @brief   Thêm phần tử vào cuối hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @param   data    Giá trị cần thêm vào hàng đợi.
 * @return  void
 */
void enqueue(Queue *queue, int data);

/**
 * @brief   Xóa phần tử từ đầu hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int dequeue(Queue *queue);

/**
 * @brief   Lấy giá trị của phần tử đứng đầu hàng đợi (front).
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int front(Queue queue);

/**
 * @brief   Lấy giá trị của phần tử đứng cuối hàng đợi (rear).
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int rear(Queue queue);

/**
 * @brief   Hiển thị các phần tử trong hàng đợi.
 * @param   q   Thông tin của hàng đợi.
 * @return  void
 */
void display(Queue q);

