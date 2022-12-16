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
	ins(88);
	ins(74);
	ins(63);
	ins(55);
	ins(37);
	ins(25);
	ins(33);
	ins(19); //������ �Է�
	ins(26);
	ins(14);
	ins(9);

	for (i = 1; i <= n; ++i)
		printf("%d(%d)  ", a[i],i);
	return 0;
}
/*

	���� ���Ŀ��� �ִ� ���� ����� �ڿ��� ���� �ִ´�.

	37�� �迭���� 5�� °�� �ִ� ���� �� �� �ִ�.
	�׷��ٸ� 37�� ������ 10�� °�� �ִ� 14�̰� �������� 11�� °�� �ִ� 9��.

	4���� ��.

*/