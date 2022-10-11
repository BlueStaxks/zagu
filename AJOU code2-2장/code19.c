#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char c[7][3] = {""};
	for (int i = 0; i < 5; ++i)
		scanf("%c", c[0] + i); //c + i라고 하면 c[0][0], c[1][0] 순으로 올라간다. 
	for (int i = 0; i < 5; ++i)
		printf("%c", *(c[0] + i));
	return 0;
}