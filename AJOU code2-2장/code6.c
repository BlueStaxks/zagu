#include <stdio.h>
int main()
{
	int aray[] = { 100,200,300,400,500 };
	int* ptr;
	ptr = aray;
	printf("%d\n", *(ptr + 3) + 100);
	//ptr�� aray�� ù ���� 100�� �ּҰ� �ǰ� �ű⿡ 3�� ���ϸ� aray[3]�� �ּҰ� �ȴ�.
	//�� �ּ��� ���� 100�� ���� 500�� ��µȴ�.
	return 0;
}