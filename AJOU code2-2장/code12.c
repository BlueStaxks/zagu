#include <stdio.h>
public static int xxx(int n);
{
	if (n == 0)	return 4;
	return 1 + xxx(n - 1);
}
int main()
{
	printf("%d ", xxx(5));
	/*
	
	실행은 불가능하지만 재귀함수라고 생각하고 생각해보면
	처음에 5가 들어가고 xxx(4) + 1이 된다.
	4가 들어가면 또 xxx(3) + 1, ~~~ 이고
	xxx(0)이되면 4가 되므로 4 + 1 + 1 + 1 + 1 + 1
						 0   1   2   3   4   5
	즉 9가 나온다.

	4번이 답이다.
	*/
	return 0;
}