/*

	A[4][2][3]이 있다. A[0][0][0]부터 1, 2, 3 ~ 24까지 입력했다.
	A[2][1][2]는 A[0][0][0]에서 2*(2*3) + 1*3 + 2만큼, 17만큼 떨어져 있다.
	1만큼 떨어지면 2이므로 A[2][1][2]에는 18이 들어가 있을 것이다.

	2번이 답.
	
*/
#include <stdio.h>
int main()
{
	int A[4][2][3] = {0};
	int i;
	for (i = 1; i <= 24; ++i)
		*(A[0][0] + i - 1) = i;
	printf("%d", A[2][1][2]);
	return 0;
}