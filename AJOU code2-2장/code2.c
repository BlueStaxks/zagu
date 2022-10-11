#include <stdio.h>
int main()
{
	int i, j = 10;
	int* p1;
	char* p2;

	p1 = &i; //p1에 i의 위치를 넣는다. --> *p1은 i값
	p2 = &j; //p2에 j의 위치를 넣는다. 그런데 p2는 char 형식 포인터이므로 형식이 맞지 않다.
	*p1 = j; //p1위치의 값을 j로 한다.
	i = *p1; //i의 값을 p1위치의 값으로 한다.

	//(2)번인 p2=&j;가 틀린 명령어다.
	return 0;
}