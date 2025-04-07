#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main()
{
    FILE *file;
    file = fopen("file.csv", "r");

    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return 1;
    }

    char line[MAX_LINE];
    char name_to_find[50];

    printf("Nhap ten can tim: ");
    fgets(name_to_find, sizeof(name_to_find), stdin);
    name_to_find[strcspn(name_to_find, "\n")] = 0; // Xóa ký tự '\n' ở cuối chuỗi

    int found = 0;
    printf("Cac truong hop khop \n");

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, name_to_find) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Khong tim thay ten trong file\n");
    }

    fclose(file);
    return 0;
}