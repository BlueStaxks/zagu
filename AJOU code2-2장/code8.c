#include <stdio.h>
int ex1(int n)
{
	static int r = 1;
	r *= n;
	if (n == 1) return r;
	ex1(n - 1);
}
int ex2(int n)
{
	if (n == 1)	return 1;
	if (n < 4)	return n - 1;
	return ex2(n - 1) + ex2(n - 2);
}
int ex4(int n)
{
	static int r = 0;
	if (!n)	return r;
	r += n;
	ex4(n - 1);
}
int main()
{
	/*1��*/
	printf("%d\n", ex1(4)); //��ͷ� ����

	/*2��*/
	printf("%d\n", ex2(4)); //��ͷ� ����

	/*3��*/
	//���

	/*4��*/
	printf("%d\n", ex4(9)); //��ͷ� ����

	//3���� �ȵ�
	return 0;
}