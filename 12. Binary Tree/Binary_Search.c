#include <stdio.h>

#define NO_FOUND -1    

int binarySearch(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;

        if (arr[mid] == x){
            return mid;
        }
        else if (arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);
        }
        else{
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return NO_FOUND;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == NO_FOUND)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}