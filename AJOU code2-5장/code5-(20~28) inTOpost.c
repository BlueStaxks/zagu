#include <stdio.h>
int us(char a)
{
	if (a == '(' || a == ')')
		return 100;
	else if (a == '*' || a == '/' || a == '%' || a == '^')
		return 10;
	else if (a == '+' || a == '-')
		return 5;
	else if (a == '=')
		return 1;
}
void huwi(char a[]) //숫자는 1의 자리 수만 처리 가능
{
	int i, p = -1;
	char s[10000] = { "" };

	for (i = 0; a[i] != '\0'; ++i)
	{
		if (('0' <= a[i] && a[i] <= '9') || ('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //숫자, 알파벳
			printf("%c", a[i]);
		else if (p == -1)
			s[++p] = a[i]; //스택 비었으면 그냥 추가
		//-----여기부턴 스택이 비지 않고, a[i]는 연산자임
		else if (a[i] == ')')
		{
			while (s[p] != '(')
				printf("%c", s[p--]);
			p--;
		}
		else if (s[p] == '(' || us(s[p]) < us(a[i])) //s[p] < a[i] (우선순위)   수가 클 수록 높음
			s[++p] = a[i]; //스택 추가
		else if (us(s[p]) >= us(a[i]))
		{
			while (s[p] != '(' && us(s[p]) >= us(a[i]) && p >= 0)
				printf("%c", s[p--]);
			s[++p] = a[i]; //스택 추가
		}
	}
	while (p >= 0) //남은거 다 출력
		printf("%c", s[p--]);
	printf("\n\n");
}
int main()
{
	//20번
	huwi("a*(b+c)*d"); //4번이 답.

	//21번
	huwi("A=(B-C)*D+E"); //3번이 답.

	//22번
	huwi("a*(b-c/5)+(d-8*e/5)"); //2번이 답.

	//23번
	huwi("a+(b*c-d)*(e-f*g)-h"); //4번이 답.

	//24번
	huwi("(((A/B)+C)-(D*E))"); //2번이 답.

	//25번
	huwi("(A*B)+(C*D)"); //3번이 답.

	//26번
	//reverse Polish는 후위 표기법과 같은 말이라고 보면 된다.
	huwi("(A+B)*(C+D)"); //1번이 답.

	//27번
	huwi("Y=(1+((3+4/2)*5))-6"); //4번이 답.

	//28번
	huwi("(7+6/2)/2+9*4/3"); //5번이 답.

	return 0;
}