#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char c[1000] = { "" };
	scanf("%[^\n]s", c);
	for (int i = 0; c[i] != '\0'; ++i)
	{
		char* p = c + i;
		if (65 <= *p && *p <= 90)
			printf("%c", *p + 32);
		else if (97 <= *p && *p <= 122)
			printf("%c", *p - 32);
		else
			printf("%c", *p);
	}
	return 0;
}