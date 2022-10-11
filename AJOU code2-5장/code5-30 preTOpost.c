#include <stdio.h>
int main()
{
	char b[] = "-+-AB*/CDEF"; //전위 -> 후위
	char s[1000][1000] = { "" };
	int i, j, k, po = -1;

	char a[1000];
	for (i = 0; b[i] != '\0'; ++i);
	for (i--, k = i; i >= 0; --i)
		a[k - i] = b[i];
	a[k + 1] = '\0';
	for (i = 0; a[i] != '\0'; ++i)
	{
		if (('0' <= a[i] && a[i] <= '9') || ('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //숫자, 알파벳
		{
			s[++po][0] = a[i];
			s[po][1] = '\0';
		}
		else
		{
			char tb[1000];
			char tc[1000];
			for (j = 0; j < 1000; ++j)
			{
				tb[j] = s[po - 1][j];
				tc[j] = s[po][j];
			}
			for (j = 0; tc[j] != '\0'; ++j)
				s[po - 1][j] = tc[j];
			int k = j;
			for (; tb[j - k] != '\0'; ++j)
				s[po - 1][j] = tb[j - k];
			s[po - 1][j] = a[i];
			s[po - 1][j + 1] = '\0';
			po--;
		}
	}
	for (i = 0; s[0][i] != '\0'; ++i)
		printf("%c", s[0][i]);
	return 0;

	//AB-CD/E*+F-
	//  1  2 34 5
	
	//2번이 답.
}