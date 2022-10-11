#include <stdio.h>
int main()
{
	int array[2][4];
	printf("원소 개수 : %d\n전체 용량 : %d\n", sizeof(array)/sizeof(int), sizeof(array));
	return 0;
}