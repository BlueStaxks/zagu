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
	//��
	huwi("A+B-C-D"); //AB+C-D-

	//��
	huwi("(A+B)*C+D"); //AB+C*D+

	//��
	huwi("A/B/C/D"); //AB/C/D/

	return 0;
}