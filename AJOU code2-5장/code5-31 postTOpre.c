#include <stdio.h>
int main()
{
	char a[] = "ABC+D/-AE+BF*/+"; //후위 -> 전위
	char s[1000][1000] = { "" };
	int i, j, po = -1;
	
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
			s[po-1][0] = a[i];
			for (j = 1; tb[j - 1] != '\0'; ++j)
				s[po - 1][j] = tb[j - 1];
			int k = j;
			for (; tc[j - k] != '\0'; ++j)
				s[po - 1][j] = tc[j - k];
			s[po - 1][j] = '\0';
			po--;
		}
	}
	for (i = 0; s[0][i] != '\0'; ++i)
		printf("%c", s[0][i]);
	return 0;

	//1번이 답.
}