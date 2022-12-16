#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void quickSort(char arr[], int L, int R)
{
    int left = L, right = R;
    int pivot = (L + R) >> 1;
    do
    {
        while (arr[left] < arr[pivot])   left++;
        while (arr[right] > arr[pivot])  right--;
        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (L < right)  quickSort(arr, L, right);
    if (left < R)   quickSort(arr, left, R);
}

void QuickSort(int* data, int n)
{
    quickSort(data, 0, n - 1);
}


void main()
{
	char data[8] = { 'B','I','D','O','Z','L','H' };
	puts(data);
	QuickSort(data, 7);
	puts(data);
}