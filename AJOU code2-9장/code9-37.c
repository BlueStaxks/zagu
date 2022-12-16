/*

	�� ������ pivot�� ����Ͽ� ������ ��� ���� ���� ������� �����Ѵ�.
	�� ������ nlog2n�� �ð��� �ɸ��ٰ� ǥ������� ���Ҹ� ��ȯ�ϴ� ������ ���� ������
	������ �ٸ� nlog2n���� ������. Ư�� n�� Ŀ�� ���� ���̴� �ε巯����.

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