#include "..\\Header\\Linear_Queue.h"

// khởi tạo hàng đợi
void initialize(Queue *queue, int size)
{
    queue->size  = size;
    queue->item  = (int*)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
}

// kiểm tra hàng đợi đầy
bool isFull(Queue queue)
{
    return (queue.rear == queue.size - 1);
}

// kiểm tra hàng đợi rỗng
bool isEmpty(Queue queue)
{
    return (queue.front == -1 || queue.front > queue.rear);
}

// thêm phần tử vào cuối hàng đợi
void enqueue(Queue *queue, int data)
{
    if (isFull(*queue))
    {
        printf("Hàng đợi đầy!\n");
        return;
    }
    else
    {
        if (queue->front == -1) queue->front = queue->rear = 0;
        else queue->rear++;
        queue->item[queue->rear] = data;
        printf("Enqueue data %d\n", data);
    }
}

#define QUEUE_EMPTY -1

// xóa phần tử đầu hàng đợi
int dequeue(Queue *queue)
{
    if (isEmpty(*queue))
    {
        printf("Hàng đợi rỗng!\n");
        return QUEUE_EMPTY;
    }
    else
    {
        int dequeue_value = queue->item[queue->front];

        queue->item[queue->front] = 0;

        if (queue->front == queue->rear && queue->rear == queue->size - 1)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front++;
        }
        return dequeue_value;
    }
}

void display(Queue queue)
{
    if (isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
    }
    else
    {
        printf("Queue: ");

        for (int i=queue.front; i<=queue.rear; i++)
        {
            printf("%d ", queue.item[i]);
        }
        printf("\n");
    }
}

int front(Queue queue)
{
    if (isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
        return QUEUE_EMPTY;
    }
    else
    {
        return queue.item[queue.front];
    }
}

int rear(Queue queue)
{
    if (isEmpty(queue))
    {
        printf("Hàng đợi rỗng!\n");
        return QUEUE_EMPTY;
    }
    else
    {
        return queue.item[queue.rear];
    }
}

int main()
{ 
    Queue liQueue;

    initialize(&liQueue, 5);

    enqueue(&liQueue, 1);
    enqueue(&liQueue, 2);
    enqueue(&liQueue, 3);
    enqueue(&liQueue, 4);
    enqueue(&liQueue, 5);
    enqueue(&liQueue, 6);

    printf("Front: %d\n", front(liQueue));
    printf("Rear: %d\n", rear(liQueue));

    display(liQueue);

    printf("Dequeue %d\n", dequeue(&liQueue));
    // printf("Dequeue %d\n", dequeue(&liQueue));
    // printf("Dequeue %d\n", dequeue(&liQueue));
    // printf("Dequeue %d\n", dequeue(&liQueue));
    // printf("Dequeue %d\n", dequeue(&liQueue));

    display(liQueue);

    enqueue(&liQueue, 10);

    return 0;
}


