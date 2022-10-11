#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void multPoly(int a[], int b[], int c[])
{
	int i, j, d = 0;
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 5; ++j)
			c[i + j] += a[i] * b[j];

	for (i = 0; i < 8; ++i)
		if (c[i])
		{
			if (d)	printf(" + ");
			d = 1;
			printf("(%d)x^%d", c[i], 8 - i);
		}
	if(c[i])	printf(" + (%d)\n", c[i]);
}
int main()
{
	int a[5] = { 0 }; //4 3 2 1 0
	int b[5] = { 0 };
	int c[9] = { 0 }; //8 7 6 5 4 3 2 1 0
	int i, j;
	printf("ù ���׽��� ����� �ְ� ���׺��� ���ʴ�� �Է��ϼ��� (�ִ� 4���ı���)\n");
	for (i = 0; i < 5; ++i)
		scanf("%d", &a[i]);
	printf("��° ���׽��� ����� �ְ� ���׺��� ���ʴ�� �Է��ϼ��� (�ִ� 4���ı���)\n");
	for (i = 0; i < 5; ++i)
		scanf("%d", &b[i]);

	multPoly(a, b, c); //�Լ� ����

	return 0;
}