#include <stdio.h>
void sort(int a[], int n)
{
	int i, j, k;
	for (i = 1; i < n; ++i) {
		k = a[i];
		for (j = i - 1; j >= 0 && k < a[j]; --j)
		{
			a[j + 1] = a[j];
			for (int l = 0; l < 5; ++l)
				printf("%d ", a[l]);
			printf("\n");
		}
		a[j + 1] = k;
		for (int l = 0; l < 5; ++l)
			printf("%d ", a[l]);
		printf("\n\n");
	}
}
int main()
{
	int a[] = { 5,4,3,4,1 };
	sort(a, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d ", a[i]);
	return 0;
}
/*

	4¹øÀÌ ´ä.

*/