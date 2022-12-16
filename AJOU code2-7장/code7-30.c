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
	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return;
}
int main()
{
	int i, j;
	ins(200);
	ins(192);
	ins(63);
	ins(72);
	ins(185);
	ins(60);
	ins(62);
	ins(16);
	ins(52);
	ins(37);
	ins(22);
	ins(11);
	ins(5);
	ins(38); //데이터 입력

	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]); //문제 상황과 동일한 배열임을 알 수 있다.
	printf("\n");

	del();
	del();
	del();

	//72 52 63 16 38 60 62 11 5 37 22
	//3번이 답.

	return 0;
}