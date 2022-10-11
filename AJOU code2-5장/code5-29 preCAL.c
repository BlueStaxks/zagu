#include <stdio.h>
int main()
{
	char a[] = "+-54*47"; //1의 자리 숫자만 계산 가능
	int s[1000] = { 0 };
	int i = 0, p = -1, t1 = NULL, t2 = NULL;

	while (a[i++] != '\0');
	i -= 2;
	for (; i >= 0; --i)
	{
		if ('0' <= a[i] && a[i] <= '9')
			s[++p] = a[i] - '0';
		else
		{
			int t2 = s[p - 1];
			int t1 = s[p];
			if (a[i] == '*')	t1 *= t2;
			if (a[i] == '+')	t1 += t2;
			if (a[i] == '/')	t1 /= t2;
			if (a[i] == '-')	t1 -= t2;
			s[--p] = t1;;
		}
	}
	printf("%d", s[0]);
	return 0;

	//4번이 답.
}