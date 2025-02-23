# Advance_C_Cpp_2.2025

# COMPILER

**Khái niệm Compiler**

Compiler (Trình biên dịch) là một chương trình dịch mã nguồn (source code) của một ngôn ngữ lập trình (high-level language) thành mã máy (machine code) hoặc mã trung gian (intermediate code) để máy tính có thể hiểu và thực thi.

**Chức năng của Compiler**

1. Phân tích mã nguồn – Kiểm tra cú pháp, cấu trúc và báo lỗi nếu có.
2. Tối ưu hóa mã – Cải thiện hiệu suất của chương trình.
3. Sinh mã đích – Chuyển đổi mã nguồn thành mã có thể thực thi trên phần cứng.

**Các loại Compiler**

Trình biên dịch trực tiếp (Ahead-of-Time Compiler - AOT): Chuyển đổi toàn bộ mã nguồn thành mã máy trước khi chạy, ví dụ:

- GCC(cho C, C++)
- Clang (cho C, C++)
- Java Compiler (javac)

Trình biên dịch JIT (Just-In-Time Compiler): Biên dịch trong quá trình thực thi chương trình, ví dụ:

- JVM (Java Virtual Machine)
- .NET CLR (Common Language Runtime)

**Ví dụ về Compiler**

```C
gcc main.c -o main
./main
```

# MARCO

Macro là một đoạn mã được định nghĩa trước và có thể được thay thế vào mã nguồn trong quá trình biên dịch. Nó thường được sử dụng để thay thế các giá trị cố định, viết tắt các đoạn code lặp lại hoặc thực hiện các phép toán đơn giản trước khi chương trình được biên dịch.

**Ưu điểm**

- Giảm lặp lại mã.
- Cải thiện hiệu suất (trong một số trường hợp).
- Giúp dễ dàng chỉnh sửa các giá trị dùng nhiều lần.

**Nhược điểm**
- Khó debug hơn so với hàm thông thường.
- Có thể làm tăng kích thước mã nếu lạm dụng.
- Không có kiểm tra kiểu dữ liệu (type checking) trong C/C++.

**Nhóm chỉ thị Marco**

1. Chỉ thị #include
Chỉ thị #include dùng để chèn nội dung của một file vào mã nguồn chương trình.
- Tái sử dụng mã nguồn
- Phân chia chương trình thành các phần nhỏ, giúp quản lý mã nguồn hiệu quả

2. Chỉ thị tiền xử lý #define. #undefine
- Macro là một khái niệm dùng để định nghĩa một tập hợp các hướng dẫn tiền xử lý
- Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
- Giúp giảm lặp lại mã, dễ bảo trì chương trình.
- Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define
- Chỉ thị #undef dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng #define

3. Chỉ thị tiền xử lý #if, #elif, #else
- #if sử dụng để bắt đầu một điều kiện tiền xử lý.
- Nếu điều kiện trong #if là đúng, các dòng mã nguồn sau #if sẽ được biên dịch
- Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp #endif
- #elif dùng để thêm một điều kiện mới khi điều kiện trước đó trong #if hoặc #elif là sai
- #else dùng khi không có điều kiện nào ở trên đúng.

4. Chỉ thị tiền xử lý #ifdef, #ifndef
- #ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
- #ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch

**Một số toán tử trong Marco**

1. Variadic macro
- Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
- Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau

```C
#define MACRO_NAME(...) //Body marco
```