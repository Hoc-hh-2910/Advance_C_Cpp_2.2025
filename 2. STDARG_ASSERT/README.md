# Advance_C_Cpp_2.2025

# STDARG - ASSERT

**Thư viện stdarg**

- Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.
- Các hàm như printf và scanf là ví dụ điển hình 
- **va_list**: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- **va_start**: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- **va_arg**: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
- **va_end**: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

```C
#include <stdio.h>
#include <stdarg.h>

void display(int count, ...) {
    va_list args;
    va_start(args, count);
   

    for (int i = 0; i < count; i++) {
        printf("Value at %d: %d\n", i, va_arg(args,int)); 
    }

    va_end(args);
}

int main()
{
    display(5, 5, 8, 15, 10, 13);

    return 0;
}
```
**Ứng dụng của stdarg.h**
Dùng khi viết hàm có số lượng tham sô không cố định, như:

- ``printf()``, ``scanf()``
- Hàm logging/debugging ``log_debug("Error at %s:%d", filename, line_number);``
- Hàm xử lý danh sách đối số động ``(compute_average(5, 3.5, 4.2, 5.0, 4.8, 3.9);)``

**Thư viện assert**

- Cung cấp macro assert. 
- Macro này được sử dụng để kiểm tra một điều kiện. 
- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
- Dùng trong debug, dùng #define NDEBUG để tắt debug

```C
#include <assert.h>
void assert(expression);
```

- Nếu ``expression`` là ``true``(khác 0) -> Chương trình chạy bình thường

- Nếu ``expression`` là ``false``(bằng 0) -> Chương trình dừng lại và hiển thị thông báo lỗi kèm trên file, dòng code và điều kiện sai.

**Ví dụ**
```C
#include <stdio.h>
#include <assert.h>

int main() {
    int x = 5;

    assert(x == 5);

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d", x);
    
    return 0;
}

```

**Ứng dụng của ``assert()``**

- Kiểm tra đầu vào hàm (``assert(n > 0);``để đảm bảo số dương)
- Kiểm tra con trỏ (``assert(ptr != NULL);``)
- Kiểm tra điều kiện logic(``assert(x < y);`` để đảm bảo thứ tự hợp lệ)
- Debug trong quá trình phát triển

**Không nên dùng ``assert()`` trong chương trình chạy thực tế, vì nó dừng chương trình ngay lập tức nếu điều kiện sai**