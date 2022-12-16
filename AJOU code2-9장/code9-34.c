#include <stdio.h>

void bubble(int a[], int n)
{
	int i, j;
	for (i = n - 1; i >= 0; --i)
		for (j = 0; j < i; ++j);
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
}

int main() {
	int data[5] = { 2,5,1,4,3 };
	bubble(data, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}