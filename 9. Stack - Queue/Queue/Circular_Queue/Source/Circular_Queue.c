#include "..//Header//Circular_Queue.h"

// khởi tạo hàng đợi
/**
 * @brief   Khởi tạo hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @param   size    Số lượng phần tử tối đa của hàng đợi.
 * @return  void
 */
void queue_Init(Queue *queue, int size)
{
    queue->items = (int*)malloc(size * sizeof(int));
    queue->size  = size;
    queue->front = queue->rear = -1;
}

// kiểm tra hàng đợi rỗng
/**
 * @brief   Kiểm tra hàng đợi có rỗng hay không.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int queue_IsEmpty(Queue queue)
{
    return (queue.front == -1);
}

// kiểm tra hàng đợi đầy
/**
 * @brief   Kiểm tra hàng đợi có đầy hay không.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int queue_IsFull(Queue queue)
{
    return (queue.rear + 1) % queue.size == queue.front;
}

// thêm phần tử vào cuối hàng đợi
/**
 * @brief   Thêm phần tử vào cuối hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @param   data    Giá trị cần thêm vào hàng đợi.
 * @return  void
 */
void enqueue(Queue *queue, int data)
{
    if (queue_IsFull(*queue))
    {
        // nếu queue đầy thì không cho thêm phần tử vào
        printf("Hàng đợi đầy!\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = data;
        printf("Enqueued %d\n", data);
    }
}

#define QUEUE_EMPTY -1

// xóa phần tử từ đầu hàng đợi
/**
 * @brief   Xóa phần tử từ đầu hàng đợi.
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int dequeue(Queue *queue)
{
    if (queue_IsEmpty(*queue))
    {
        // nếu queue rỗng thì không cho xóa
        printf("Hàng đợi rỗng\n");
        return QUEUE_EMPTY;
    }
    else
    {
        int dequeue_value = queue->items[queue->front];
        if (queue->front == queue->rear && (queue->rear ==  queue->size - 1))
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeue_value;
    }
}

// lấy giá trị của phần tử đứng đầu hàng đợi (front)
/**
 * @brief   Lấy giá trị của phần tử đứng đầu hàng đợi (front).
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int front(Queue queue)
{
    if (queue_IsEmpty(queue))
    {
        printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }
    else
    {
        return queue.items[queue.front];
    }
}

// lấy giá trị của phần tử đứng cuối hàng đợi (rear)
/**
 * @brief   Lấy giá trị của phần tử đứng cuối hàng đợi (rear).
 * @param   queue   Thông tin của hàng đợi.
 * @return  int
 */
int rear(Queue queue)
{
    if (queue_IsEmpty(queue))
    {
        printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }
    else
    {
        return queue.items[queue.rear];
    }
}

// Hiển thị các phần tử
/**
 * @brief   Hiển thị các phần tử trong hàng đợi.
 * @param   q   Thông tin của hàng đợi.
 * @return  void
 */
void display(Queue q)
{
    if (queue_IsEmpty(q))
    {
        printf("Hàng đợi rỗng\n");
        return;
    }
    printf("Hàng đợi: ");
    int i = q.front;

    while (1)
    {
        printf("%d ", q.items[i]);
        if (i == q.rear) break;
        i = (i + 1) % q.size;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    Queue queue;
   
    queue_Init(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25);
    enqueue(&queue, 30);

    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));

    display(queue);

    enqueue(&queue, 50);
    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    return 0;
}

