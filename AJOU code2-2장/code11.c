#include <stdio.h>
int recursive(int n)
{
	if (n < 1)	return 2;
	else return (22 * recursive(n - 1) + 1);
}
int main()
{
	printf("%d", recursive(4));
	//2에 *22 +1에 *22 +1 에 *22 +1 에 *22 +1
	//0      1       2         3         4
	//479667가 된다.

	//답 선지에는 답이 없다.
	return 0;
}