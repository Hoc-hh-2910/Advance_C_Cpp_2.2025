#include <stdio.h>
#include <stdint.h>

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

typedef uint8_t CarColor; //Màu sắc của xe
typedef uint8_t CarPower;  //Công suất của xe
typedef uint8_t CarEngine; //Loại động cơ của xe



#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn


typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
    
} CarOptions;

void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}


void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    /*
        011
        AND
        010
        ---
        010    
    */
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
    /*
         011
         AND
         100
         ---
         000
    */
}

int main() {
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0); // Options:000, Black:10, 150HP:01, 20L:1 -> 1011 0000	

    setOption(&myCar, SUNROOF_MASK); 
    /*  1011 0000
        OR 
        0000 0001
        --------
        1011 0001 */ 
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    /*  1011 0001
        OR 
        0000 0010
        --------
        1011 0011 */
    displayCarOptions(myCar);
    /*
    Kết quả trả ra sẽ là:
    Color: Black
    Power: 150HP
    Engine: 2.0L
    Sunroof: Yes
       011
       AND
       001
       ---
       001
    Premium Audio: Yes
        011
        AND
        010
        ---
        010
    Sports Package: No
        011
        AND
        100
        ---
        000
    */

    unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
    /*  1011 0011
        AND
       ~0000 0010
        --------
        1011 0011
        AND 
        1111 1101
        --------
        1011 0001 */
    displayCarOptions(myCar);
    /*
    Kêt quả trả ra sẽ là:
    Color: Black
    Power: 150HP
    Engine: 2.0L
    Sunroof: Yes
        001
        AND
        001
        ---
        001
    Premium Audio: No
        001
        AND
        010
        ---
        000
    Sports Package: No
        001
        AND
        100
        ---
        000
    */
    printf("size of my car: %d\n", sizeof(CarOptions)); // 8 bits = 1 byte

    return 0;
}



