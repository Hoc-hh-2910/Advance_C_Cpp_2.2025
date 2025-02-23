# Advance_C_Cpp_2.2025

# Pointer

**Khái niệm:**
- Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:

```C
int test; // Address: 0x01, Value: 0
```

```C
int *ptr = &test;   // Address: 0xF1, Value: 0x01
ptr;    //0x01
*ptr;   // 0
```
- Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý.

```C
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %d bytes\n", size(ptr)); //4 byte
    return 0;
}
```

**Phân loại:**

1. Void Pointer

Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

```C
void *ptr_void;
```

2. Function Pointer

- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

```C
<return_type> (* func_pointer)(<data_type_1>, <data_type_2>);
```

***Example:***

```C
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```

3. Pointer to Constant

Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

```C
int const *ptr_const; 
const int *ptr_const;
```

4. Constant Pointer

Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

```C
int *const const_ptr = &value;
```

5. Pointer to Pointer
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.

```C
int test = 5;   // Address: 0x01, Value: 5
```

```C
int *ptr = &test;   // Address: 0xF1, Value: 0x01
```

```C
int **ptp = &ptr;   // Address: 0xEF, Value: 0xF1 
```

Ứng dụng: Kiểu dữ liệu json, cấu trúc dữ liệu list

6. NULL Pointer

- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null, C++ (NULL, nullptr).
- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.


# Bài tập

**Đã được phân tích trong Ex5.c của Function_Pointer**