#include <stdio.h>
int main()
{
	/*1번*/
	int a;
	int* b;
	b = &a;

	/*2번*/ 
	char c[10];
	char* d;
	d = c;

	/*3번*/
	int* e = (int*)malloc(sizeof(int) * 4);

	/*4번*/
	int 0x6C4FF754; //될 리가 없다.

	//4번이 안됨
	return 0;
}