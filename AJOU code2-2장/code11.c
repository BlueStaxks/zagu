#include <stdio.h>
int recursive(int n)
{
	if (n < 1)	return 2;
	else return (22 * recursive(n - 1) + 1);
}
int main()
{
	printf("%d", recursive(4));
	//2�� *22 +1�� *22 +1 �� *22 +1 �� *22 +1
	//0      1       2         3         4
	//479667�� �ȴ�.

	//�� �������� ���� ����.
	return 0;
}