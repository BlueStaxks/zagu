#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a;
	char c;
	scanf("%d", &a);
	//getchar();
	scanf("%c", &c);
	printf("*%c*", c);
	return 0;
}

/*

위 프로그램을 실행시켜보면 정수를 하나 입력한 뒤 엔터를 치면 그 엔터키가 c에 들어가 버린다.
그렇기 때문에 정수 입력 후에 입력되는 엔터키 하나를 받아줄 애가 필요하다.
그 역할을 getchar();가 하는 것이다. 문자 하나(엔터키)를 그냥 받아 버림으로써 프로그램이 의도대로 작동하게 만들어 준다.

*/