#include <stdio.h>
void SelectionSort(int a[], int size)
{
	int i, j, min, mini;
	for (i = 0; i < size - 1; ++i)
	{
		for (j = i, min = 99999999; j < size; ++j)
		{
			if (a[j] < min)
			{
				min = a[j];
				mini = j;
			}
		}
		a[i] ^= a[mini] ^= a[i] ^= a[mini];
		for (j = 0; j < size; ++j)
			printf("%d ", a[j]);
		printf("\n\n");
	}
}
int main()
{
	int a[] = { 8,3,4,9,7 };
	SelectionSort(a, 5);
	return 0;
}
/*

	3�� ° �� �� 3 4 7 9 8 �� ���� �� �� �ִ�.

	1���� ��.

*/