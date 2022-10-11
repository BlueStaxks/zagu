#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int n)
{
	static int r = 0;
	r += n;
	if (n == 1)	return r;
	sum(n - 1);
}
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", sum(a));
	return 0;
}