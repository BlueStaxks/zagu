#include <stdio.h>
void bubbleSort(int a[], int size)
{
	int i, j;
	for (i = size - 1; i >= 0; --i)
	{
		for (j = 0; j < i; ++j)
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			} //a[j] ^= a[j + 1] ^= a[j] ^= a[j + 1];
		for (j = 0; j < size; ++j)
			printf("%d ", a[j]);
		printf("\n\n");
	}
}
int main()
{
	int a[] = { 8,5,6,2,4 };
	bubbleSort(a, 5);
	return 0;
}
/*

	1번 째 후 5 6 2 4 8 인 것을 알 수 있다.

	3번이 답.

*/