#include <stdio.h>
int main()
{
	/*1��*/
	int a;
	int* b;
	b = &a;

	/*2��*/ 
	char c[10];
	char* d;
	d = c;

	/*3��*/
	int* e = (int*)malloc(sizeof(int) * 4);

	/*4��*/
	int 0x6C4FF754; //�� ���� ����.

	//4���� �ȵ�
	return 0;
}