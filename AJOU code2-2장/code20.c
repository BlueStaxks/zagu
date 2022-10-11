#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char a, b;
	scanf("%c%c", &a, &b);
	a == b ? printf("같음") : printf("다름");
	return 0;
}