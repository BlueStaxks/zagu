#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void reverse(char c[])
{
	int i;
	for (i = 0; c[i] != '\0'; ++i);
	for (i--; i >= 0; --i)
		printf("%c", c[i]);
}
int main()
{
	char c[1000] = { "" };
	scanf("%[^\n]s", c);
	reverse(c);
}