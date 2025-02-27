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

Ta có các giá trị được định nghĩa trước như sau:

```C
// Định nghĩa các hằng số cho màu sắc
#define COLOR_RED 0	    //00
#define COLOR_BLUE 1    //01
#define COLOR_BLACK 2   //10
#define COLOR_WHITE 3   //11
// Định nghĩa các hằng số cho công suất
#define POWER_100HP 0   //00
#define POWER_150HP 1   //01
#define POWER_200HP 2   //10
// Định nghĩa các hằng số cho loại động cơ
#define ENGINE_1_5L 0   //0
#define ENGINE_2_0L 1   //1
```

Ta định nghĩa các biến theo datatype

```C
typedef uint8_t CarColor; //Màu sắc của xe
typedef uint8_t CarPower;  //Công suất của xe
typedef uint8_t CarEngine; //Loại động cơ của xe
```

Dùng Bitmask để định nghĩa các giá trị

```C
#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
```

Cấu hình của xe sẽ được khai bảo bằng hàm ``Struct`` và định nghĩa độ dài các biến cụ thể

```C
typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
    
} CarOptions;
```

Khi khởi chạy hàm main thì ta sẽ cấu hình cho xe thông qua hàm

```C
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0); // Options:000, Black:10, 150HP:01, 20L:1 -> 1011 0000	
```

với các thông số được cấu hình như sau:

```C
void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;                 // 10
    car->power = power;                 // 01
    car->engine = engine;               //1
    car->additionalOptions = options;   //Options:000

    // Output: 10011000
}
```

Tiếp theo ta thực hiện hàm để cấu hình SUNROOF cho xe

```C
setOption(&myCar, SUNROOF_MASK); 
```

```C
void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}

    /*  1001 1000 : My Car
        OR 
        0000 0001 : SUNROOF_MASK
        --------
        1001 1001 : OUTPUT 
    */ 
```

Tương tự với set PREMIUM_AUDIO

```C
setOption(&myCar, PREMIUM_AUDIO_MASK);

    /*  1001 1001 : My car
        OR 
        0000 0010 : PREMIUM_AUDIO
        --------
        1001 1011 : OUTPUT
    */
```

Sau đó ta dùng hàm ``displayCarOption`` để hiển thị những cấu hình của xe hiện tại

```C
displayCarOptions(myCar);
```

Khi đó hiện thị sẽ như sau:

```C
void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]); //car.color: 10 = 2 -> Black
    printf("Power: %s\n", powers[car.power]); //car.power: 01 = 1 -> 150HP
    printf("Engine: %s\n", engines[car.engine]); // car.engine: 1 -> 2.0L
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No"); // 011 & 001 = 001 -> Yes
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No"); // 011 & 010 = 010 -> Yes
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No"); // 011 & 100 = 000 -> No

```

Tiếp theo là khi ta muốn tắt tính năng đi thì sẽ sử dụng hàm ``unsetOption``

```C
unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
```

Khi đó kết quả sẽ chạy như sau: 

```C

void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}

    /*  1011 0011 : My car
        AND
       ~0000 0010 : ~ Premium_audio (0000 0010)
        --------
        1011 0011 
        AND 
        1111 1101 
        --------
        1011 0001 : Output 
    */
```

Sau đó để kiểm tra lại thì ta lại sử dụng hàm ``displayCarOption``