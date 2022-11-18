/*

	우선순위 큐는 히프를 통해 구현할 수 있다.
	수가 클 수록 우선순위가 높다고 하였으니 최대 히프를 구현해서 히프를 삭제하는 것이 pop이 될 것이다.

*/
#include <stdio.h>
#include <stdlib.h>
int a[1000] = { 0 };
int n = 0;
void ins(int k)
{
	if (n == 999)	return;
	n++;
	int i = n;
	while (!(i == 1 || k <= a[i / 2]))
	{
		a[i] = a[i / 2];
		i = i >> 1;
	}
	a[i] = k;
	return;
}
void del()
{
	if (!n)	return;
	int k = a[1];
	int t = a[n];
	n--;
	int i = 1;
	int j = 2;
	while (j <= n)
	{
		if (j < n && a[j] < a[j + 1])
			j++;
		if (t >= a[j])	break;
		a[i] = a[j];
		i = j;
		j = j << 1;
	}
	a[i] = t;
	return;
}
int main()
{
	int i, j;
	ins(24);
	ins(17);
	ins(29);
	ins(22);
	ins(20);
	ins(31);
	ins(27);
	ins(18);
	ins(21); //데이터 입력

	del();//루트 삭제 후 정리

	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;

	//마지막이 17인 것을 볼 수 있다.
	//1번이 답.
}