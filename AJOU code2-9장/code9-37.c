/*

	퀵 정렬은 pivot을 사용하여 기준을 잡고 분할 정복 방식으로 정렬한다.
	퀵 정렬은 nlog2n의 시간이 걸린다고 표기되지만 원소를 교환하는 과정이 적기 때문에
	실제로 다른 nlog2n보다 빠르다. 특히 n이 커질 수록 차이는 두드러진다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void quickSort(int arr[], int L, int R)
{
    int left = L, right = R, i;
    int pivot = (L + R) >> 1;
    for (i = 0; i < 9; ++i)
        printf("%d ", arr[i]);
    printf("\n\n");
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

void main()
{
    int data[] = { 30,15,16,24,38,33,17,29,32 };
	quickSort(data, 0, 8);
    for (int i = 0; i < 9; ++i)
        printf("%d ", data[i]);
    printf("\n\n");
}