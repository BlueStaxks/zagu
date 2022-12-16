#include <stdio.h>
#include <stdlib.h>
int a[1000] = { 0 };
int n = 0;
void ins(int k)
{
	if (n == 999)	exit(1);
	n++;
	int i = n;
	while (!(i == 1 || k <= a[i / 2]))
	{
		a[i] = a[i / 2];
		i = i >> 1;
	}
	a[i] = k;
	return;
}
int main()
{
	int i, j;
	for (i = 1; i <= 8; ++i)
	{
		ins(i);
		for (j = 1; j <= n; ++j)
			printf("%d ", a[j]);
		printf("\n");
	}
	return 0;

	//6 4 5 1 3 2
	//8 7 6 4 3 2 5 1
	//4¹øÀÌ ´ä.
}