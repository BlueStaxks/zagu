#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char c[7][3] = {""};
	for (int i = 0; i < 5; ++i)
		scanf("%c", c[0] + i); //c + i��� �ϸ� c[0][0], c[1][0] ������ �ö󰣴�. 
	for (int i = 0; i < 5; ++i)
		printf("%c", *(c[0] + i));
	return 0;
}