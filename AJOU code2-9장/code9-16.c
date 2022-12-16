#include <stdio.h>
void insertionSort(int a[], int size)
{
	int i;
	for (i = 1; i < size; ++i)
	{
		int t = a[i];
		int j = i;
		while ((j > 0) && (a[j - 1] > t))
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
		for (j = 0; j < size; ++j)
			printf("%d ", a[j]);
		printf("\n\n");
	}
}
int main()
{
	int a[] = { 5,4,3,2,1 };
	insertionSort(a, 5);
	return 0;
}
/*

	3회전 후 2 3 4 5 1 인 것을 알 수 있다.

	3번이 답.

*/