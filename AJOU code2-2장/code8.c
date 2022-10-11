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
	/*1¹ø*/
	printf("%d\n", ex1(4)); //Àç±Í·Î °¡´É

	/*2¹ø*/
	printf("%d\n", ex2(4)); //Àç±Í·Î °¡´É

	/*3¹ø*/
	//¶ì¿ë

	/*4¹ø*/
	printf("%d\n", ex4(9)); //Àç±Í·Î °¡´É

	//3¹øÀÌ ¾ÈµÊ
	return 0;
}