#include <stdio.h>
int main()
{
	int aray[] = { 100,200,300,400,500 };
	int* ptr;
	ptr = aray;
	printf("%d\n", *(ptr + 3) + 100);
	//ptr은 aray의 첫 값인 100의 주소가 되고 거기에 3을 더하면 aray[3]의 주소가 된다.
	//그 주소의 값과 100의 합인 500이 출력된다.
	return 0;
}