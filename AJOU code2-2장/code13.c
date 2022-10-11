#include <stdio.h>
int c = 0;
int f(int n)
{
	c++;
	if (n == 0 || n == 1)
		return n;
	return f(n - 1) + f(n - 2);
}
int main()
{
	f(7);
	printf("%d", c);
	//c가 41이 되는 것을 알 수 있다.
	//f(7)을 계산하면서 f(5)가 계산되는데 f(6)이 계산되면서 f(5)가 또 계산되는 식으로 같은 계산을 계속 반복하여
	//재귀가 생각보다 많이 호출된다.

	//3번이 답이다.
	return 0;
}