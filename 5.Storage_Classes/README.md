# Advance_C_Cpp_2.2025

# Storage Classes

Storage Classes giúp xác định phạm vi (scope), thời gian tồn tại (lifetime), và khả năng truy cập (visibility) của biến hoặc hàm trong chương trình. 

**Extern: Lưu trữ ngoài**

- Dùng để khai báo biến toàn cục nằm trong một file khác.
- Giúp chia sẻ biến giữa các file .c.

***File test.c***

```C
#include <string.h>

char var[10];

void display(void)
{
	strcpy(var, (char*)"Hello");	
}
```

***File test1.c***

```C
#include <stdint.h>

/*
Description: delay x giay
*/
void delay(void)
{
	uint32_t i;
	for (i = 0; i < 5000000; ++i){

    }
	
}

static int count = 0;

void funCount(void)
{
	count++;
	delay(); // delay x giay
}
```

**Static local Variables**

Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.

```C
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```

**Static global variables**

- Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
- Ứng dụng: dùng để thiết kế các file thư viện.

```C
#include <math.h>

typedef struct {
    float x1;
    float x2;
} Equation;

static int A,B,C;

void inputCoefficients(int a, int b, int c) {
A = a;
B = b;
C = c;
}

static float calculateDelta() 
{
    return B * B - 4 * A * C;
}

void result(Equation *equation) {
    float delta = calculateDelta();
    if (delta > 0) {
        equation->x1 = (-B + sqrt(delta)) / (2 * A);
        equation->x2 = (-B - sqrt(delta)) / (2 * A);
    } else if (delta == 0) {
        equation->x1 = equation->x2 = -B / (2 * A);
    } else {
        equation->x1 = equation->x2 = -1;
    }
}
```

**Static trong Class**

Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.

```C
#include <iostream>

typedef enum
{
    red = 0,
    blue,
    green,
    purple,
    black,
    yellow
} Pen_Color;

void print_color_pen(Pen_Color color)
{
    switch (color)
    {
    case red:
        std::cout << "Red\n";
        break;
    case blue:
        std::cout << "Blue\n";
        break;
    case green:
        std::cout << "Green\n";
        break;
    
    default:
        break;
    }
}

class PEN
{
public:
    Pen_Color pen_color;
    static int pen_length;

    PEN(Pen_Color color);
    Pen_Color get_color()
    {
        return pen_color;
    }
    void set_length(int length)
    {
        pen_length = length;
    }
};

int PEN::pen_length;

PEN::PEN(Pen_Color color)
{
    pen_color = color;
    pen_length = 10;
}

int main(int argc, char const *argv[])
{
    PEN blue_pen(blue);
    PEN red_pen(red);
    PEN green_pen(green);

    blue_pen.set_length(9);

    std::cout << "Color: ";
    print_color_pen(blue_pen.get_color());
    std::cout << "Length: " << blue_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(red_pen.get_color());
    std::cout << "Length: " << red_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(green_pen.get_color());
    std::cout << "Length: " << green_pen.pen_length << '\n';

    return 0;
}
```

**Volatile**

Từ khóa volatile trong ngôn ngữ lập trình C/C++ được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

```C
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}

```

**Register**

Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.

```C
#include <stdio.h>
#include <time.h>

int a;
int b;

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    reigster int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 2000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```