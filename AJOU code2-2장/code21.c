#include <stdio.h>
int main()
{
	float a = 1.23, b = 4.56, t;
	float* t1;
	float* t2;
	t1 = &a;
	t2 = &b;
	
	t = *t1;
	*t1 = *t2;
	*t2 = t; //�̷��� �϶�°��� �� �𸣰����� �ϴ� ��

	printf("%f %f", a, b);
	return 0;
}