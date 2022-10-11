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
void huwi(char a[]) //���ڴ� 1�� �ڸ� ���� ó�� ����
{
	int i, p = -1;
	char s[10000] = { "" };

	for (i = 0; a[i] != '\0'; ++i)
	{
		if (('0' <= a[i] && a[i] <= '9') || ('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //����, ���ĺ�
			printf("%c", a[i]);
		else if (p == -1)
			s[++p] = a[i]; //���� ������� �׳� �߰�
		//-----������� ������ ���� �ʰ�, a[i]�� ��������
		else if (a[i] == ')')
		{
			while (s[p] != '(')
				printf("%c", s[p--]);
			p--;
		}
		else if (s[p] == '(' || us(s[p]) < us(a[i])) //s[p] < a[i] (�켱����)   ���� Ŭ ���� ����
			s[++p] = a[i]; //���� �߰�
		else if (us(s[p]) >= us(a[i]))
		{
			while (s[p] != '(' && us(s[p]) >= us(a[i]) && p >= 0)
				printf("%c", s[p--]);
			s[++p] = a[i]; //���� �߰�
		}
	}
	while (p >= 0) //������ �� ���
		printf("%c", s[p--]);
	printf("\n\n");
}
int main()
{
	//20��
	huwi("a*(b+c)*d"); //4���� ��.

	//21��
	huwi("A=(B-C)*D+E"); //3���� ��.

	//22��
	huwi("a*(b-c/5)+(d-8*e/5)"); //2���� ��.

	//23��
	huwi("a+(b*c-d)*(e-f*g)-h"); //4���� ��.

	//24��
	huwi("(((A/B)+C)-(D*E))"); //2���� ��.

	//25��
	huwi("(A*B)+(C*D)"); //3���� ��.

	//26��
	//reverse Polish�� ���� ǥ����� ���� ���̶�� ���� �ȴ�.
	huwi("(A+B)*(C+D)"); //1���� ��.

	//27��
	huwi("Y=(1+((3+4/2)*5))-6"); //4���� ��.

	//28��
	huwi("(7+6/2)/2+9*4/3"); //5���� ��.

	return 0;
}