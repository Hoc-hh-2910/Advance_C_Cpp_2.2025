# Linked List

Linked List (Danh sách liên kết) là một cấu trúc dữ liệu động bao gồm một tập hợp các node (nút) được liên kết với nhau bằng con trỏ. Không giống như mảng (array), Linked List không yêu cầu cấp phát bộ nhớ cố định mà có thể mở rộng hoặc thu nhỏ linh hoạt.

**Cấu trúc của một node trong Linked List**

Mỗi Node trong Linked List thường có 2 phần:

1. Dữ liệu (Data): Chứa giá trị của node.
2. Con trỏ (pointer): Chứa địa chỉ của node tiếp theo trong danh sách.

Ví dụ:

```C
typedef struct Node {
    int data;         // Giá trị của node
    struct Node* next; // Con trỏ trỏ đến node tiếp theo
} Node;
```

**Các loại Linked List**

1. Singly Linked List (Danh sách liên kết đơn):
- Mỗi Node chỉ trỏ đến node tiếp theo.
- Node cuối cùng trỏ đến ``NULL``
- Ví dụ:

```C
[10] -> [20] -> [30] -> NULL
```
```C
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

2. Doubly Linked List (Danh sách liên kết đôi):
- Mỗi node có 2 con trỏ: trỏ đến node trước và node sau
- Dễ dàng duyệt cả hai hướng
- Ví dụ:

```C
NULL <- [10] <-> [20] <-> [30] -> NULL
```
```C
typedef struct Node {
    int data;
    struct Node* prev; // Con trỏ trỏ đến node trước
    struct Node* next; // Con trỏ trỏ đến node sau
} Node;
```

3. Circular Linked List (Danh sách liên kết vòng):
- Node cuối cùng trỏ lại node đầu tiên, tạo thành một vòng khép kín
- Có thể là liên kết đơn hoặc liên kết đôi
- Ví dụ:

```C
[10] -> [20] -> [30] --|
  ↑                    ↓
  |---------------------|
```

**Khi nào dùng Linked List**

- Khi cần thao tác chèn/xóa nhiều (Ví dụ: quản lý hàng đợi, stack)
- Khi cần cấu trúc dữ liệu động, không biết trước kích thước.
