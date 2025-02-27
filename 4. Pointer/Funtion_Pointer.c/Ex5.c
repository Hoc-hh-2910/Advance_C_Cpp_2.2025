#include <stdio.h>
#include <string.h>

typedef struct {
   char ten[50];        // 1 byte
   float diemTrungBinh; // 4 byte
   int id;              // 4 byte
} SinhVien;

int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) // Nếu 2 kí tự bằng nhau và khác NULL
   {
       str1++;
       str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2; // Trả về hiệu 2 kí tự
}


// Hàm so sánh theo tên
int compareByName(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a; // Ép kiểu void* về SinhVien*
   SinhVien *sv2 = (SinhVien *)b; // Ép kiểu void* về SinhVien*
   return stringCompare(sv1->ten, sv2->ten); // Vì tên là mảng nên không thể so sánh trực tiếp
}

// Hàm so sánh theo điểm trung bình
int compareByDiemTrungBinh(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a; // Ép kiểu void* về SinhVien*
   SinhVien *sv2 = (SinhVien *)b; // Ép kiểu void* về SinhVien*
   if (sv1->diemTrungBinh > sv2->diemTrungBinh)
   {
       return 1;
   }
  
   return 0;
}

// Hàm so sánh theo ID
int compareByID(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a; // Ép kiểu void* về SinhVien*
   SinhVien *sv2 = (SinhVien *)b; // Ép kiểu void* về SinhVien*
   return sv1->id - sv2->id;
}

// Hàm sắp xếp chung
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) // Hàm nhận vào 1 hàm so sánh
{
   int i, j;
   SinhVien temp;
   // So sánh các phần tử đầu tiên với các phần tử còn lại
   for (i = 0; i < size-1; i++)    
       for (j = i+1; j < size; j++)
           if (compareFunc(array+i, array+j)>0) {
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
}

void display(SinhVien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
       // In ra thông tin sinh viên
   }
   printf("\n");
}

int main() {

    // Khai báo mảng sinh viên
   SinhVien danhSachSV[] = {
       {  
           .ten = "Hoang",
           .diemTrungBinh = 7.5,
           .id = 100
       },
       {
           .ten = "Tuan",
           .diemTrungBinh = 4.5,
           .id = 101
       },
       {
           .ten = "Vy",
           .diemTrungBinh = 6.8,
           .id = 102},
       {  
           .ten = "Ngan",
           .diemTrungBinh = 5.6,
           .id = 10
       },
   };

   // Tính kích thước của mảng
   size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]); // 9*4/9 = 4

   // Sắp xếp theo tên
   sort(danhSachSV, size, compareByName);
   /*
   Không cần truyền địa chỉ của hàm compareByName vì hàm compareByName đã được khai báo trước đó
   Khi đó hàm sort sẽ gọi hàm compareByName để so sánh 2 phần tử
   Kết quả sẽ là: Vy, Ngan, Tuan, Hoang
   */
   display(danhSachSV, size);

   // Sắp xếp theo điểm trung bình
   sort(danhSachSV, size, compareByDiemTrungBinh);

   display(danhSachSV, size);

   // Sắp xếp theo ID
   sort(danhSachSV, size, compareByID);

   display(danhSachSV, size);

   return 0;
}




