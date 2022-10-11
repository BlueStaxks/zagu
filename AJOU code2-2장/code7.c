#include <stdio.h>
int main()
{
	struct employee {
		char name[20];
	};

	struct employee Lee, Hong, Kim[3];
	struct employee* sp;

	/*1번*/
	sp = Kim; //Kim을 그냥 쓰면 Kim배열의 첫 항목의 위치가 되므로 이 식은 유효하다.

	/*2번*/
	sp = Lee; //형식이 맞지 않는다.

	/*3번*/
	Lee = Kim; //형식이 맞지 않는다.

	/*4번*/
	Kim[0] = Kim[3]; //Kim[3]은 잘못된 참조이다.

	/*5번*/
	sp = Kim[1]; //형식이 맞지 않는다.

	//1번이 적절함
	return 0;
}