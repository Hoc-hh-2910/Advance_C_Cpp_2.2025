# Lý thuyết:

# Bubble Sort:

Bubble Sort là một thuật toán sắp xếp đơn giản nhưng dễ hiểu

**Ý tưởng:**

Thuật toán này hoạt động bằng cách lặp đi lặp lại việc so sánh cặp phần tử liền kề và hoán đổi chúng nếu chúng không theo thứ tự mong muốn (thường là tăng dần). Mỗi vòng lặp qua sẽ "đẩy" phần tử lớn nhất (hoặc nhỏ nhất) còn lại về đúng vị trí, giống như "bọt nước nổi lên" — vì vậy gọi là bubble sort.

**Cách hoạt động:**

Giả sử ta có một mảng ``arr`` có ``n`` phần tử:

```C
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            // Hoán đổi nếu phần tử bên trái lớn hơn phần tử bên phải
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
```

- Vòng lặp ngoài i chạy từ 0 đến n - 2, tương ứng với số lần cần lặp (tối đa n-1 lần).

- Vòng lặp trong j sẽ so sánh các cặp phần tử liền kề và hoán đổi nếu cần.

- Sau mỗi vòng lặp ngoài, phần tử lớn nhất còn lại được đặt đúng vị trí ở cuối mảng (giống như nổi lên trên mặt nước).

**Ví dụ:**

Giả sử ta có mảng: [5, 3, 8, 4, 2]

Lần 1: [3, 5, 4, 2, 8]

Lần 2: [3, 4, 2, 5, 8]

Lần 3: [3, 2, 4, 5, 8]

Lần 4: [2, 3, 4, 5, 8] (đã sắp xếp)

# Binary Tree:

Một Binary Tree là một cây trong đó mỗi nút có tối đa 2 con – gọi là left child (con trái) và right child (con phải).

Ví dụ:

```C
      1
     / \
    2   3
   / \
  4   5
```

Ở đây:

- Nút 1 là root (gốc).

- Nút 2 có 2 con là 4 và 5.

- Nút 3 là lá (leaf), không có con.

# Binary Seach Tree:

Một Binary Search Tree là cây nhị phân có thêm tính chất:

Với mỗi nút node, mọi giá trị trong cây con bên trái < node, mọi giá trị trong cây con bên phải > node.

```C
      8
     / \
    3   10
   / \    \
  1   6    14
     / \   /
    4   7 13
```

- Cây này tuân thủ tính chất Binary Seach Tree.

- Mọi phần tử bên trái < 8, bên phải > 8.