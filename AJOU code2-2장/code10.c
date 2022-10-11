#include <stdio.h>
int f1(int n)
{
	if (n <= 0)	return 0;
	else if (n <= 2)	return n;
	else   return f1(n - 3) + f1(n - 2) + f1(n - 1);
}
int main()
{
	printf("%d", f1(4));
	//f1은 1 2 3 6 ... 의 수열이다.
	//그러므로 6이 나오고  4번이 답이다.
	return 0;
}