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
	//가
	huwi("A+B-C-D"); //AB+C-D-

	//나
	huwi("(A+B)*C+D"); //AB+C*D+

	//다
	huwi("A/B/C/D"); //AB/C/D/

	return 0;
}