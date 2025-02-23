# Advance_C_Cpp_2.2025

# Bitmask

**Khái niệm:**

- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.

**Phân loại:**

1. NOT bitwise:

Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.

```C
int result = ~num; // ký tự ~: NOT
```

2. AND bitwise:

Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.

```C
int result = num1 & num2; // ký tự &: AND
```

3. OR bitwise:

Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1.

```C
int result = num1 | num2; // ký tự |: OR
```

4. XOR bitwise:

Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1.

```C
int result = num1 ^ num2;
```

5. Shift left and Shift right bitwise:

Dùng để di chuyển bit sang trái hoặc sang phải.
Trong trường hợp "<<", các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.

```C
int resultLeftShift = num << shiftAmount;
```

Trong trường hợp ">>", các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

```C
int resultRightShift = num >> shiftAmount;
```

# BÀI TẬP:

**Đã được phân tích trong Ex4.c**
