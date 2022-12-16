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
	ins(21);
	ins(37);
	ins(22);
	ins(17);
	ins(11);
	ins(30);
	ins(5);
	ins(10); //데이터 입력
	ins(9);

	del();

	for (i = 1; i <= n; ++i)
		printf("%d(%d)  ", a[i], i);
	return 0;
}
/*

	히프 정렬에선 최대 힙을 만들고 뒤에서 부터 넣는다.

	내림차순으로 정렬할 때는 최대 힙을 그대로 쓰고 앞에서 부터 넣는 것 같다.
	아니면 답이 30인데 없다.

	2번이 답.

*/