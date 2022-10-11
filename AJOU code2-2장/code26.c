#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int m[1000000] = {0};
int fibo(int n)
{
	if (m[n])	return m[n];
	return m[n] = fibo(n - 1) + fibo(n - 2);
}
int main()
{
	m[1] = m[2] = 1;
	int a;
	scanf("%d", &a);
	printf("%d", fibo(a));
	return 0;
}