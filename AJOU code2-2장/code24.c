#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
	char name[100];
	char number[100];
	char address[1000];
	char birthday[100];
} list;
void view(list a[], int n)
{
	if (!n)
		printf("�ƹ��͵� �����ϴ�");
	else
		for (int i = 0; i < n; ++i)
			printf("\t%d.\t%s\t%s\t%s\t%s\n", i + 1, a[i].name, a[i].number, a[i].address, a[i].birthday);
	printf("\n\n");
}
void add(list a[], int* n)
{
	char c;
	list lt;
	printf("�̸� : ");
	scanf("%[^\n]s", lt.name);
	scanf("%c", &c);
	printf("��ȭ��ȣ : ");
	scanf("%[^\n]s", lt.number);
	scanf("%c", &c);
	printf("�ּ� : ");
	scanf("%[^\n]s", lt.address);
	scanf("%c", &c);
	printf("���� : ");
	scanf("%[^\n]s", lt.birthday);
	scanf("%c", &c);
	a[(*n)++] = lt;
	printf("�߰��Ǿ����ϴ�\n\n");
}
void search(list a[], int n)
{
	char c[1000];
	printf("ã�� ���� �Է� : ");
	scanf("%[^\n]s", c);
	int k = 0;
	for (int i = 0, f = 0; i < n; ++i, f = 0)
	{
		if (!strcmp(c, a[i].name))	f = 1;
		if (!strcmp(c, a[i].number))	f = 1;
		if (!strcmp(c, a[i].address))	f = 1;
		if (!strcmp(c, a[i].birthday))	f = 1;
		if (f)
		{
			printf("\t%d.\t%s\t%s\t%s\t%s\n", i + 1, a[i].name, a[i].number, a[i].address, a[i].birthday);
			k = 1;
		}
	}
	if(!k)
		printf("�ƹ��͵� �����ϴ�\n");
	printf("\n\n");
}
void del(list a[], int* n)
{
	if (!(*n))
	{
		printf("���� �� �����ϴ�\n\n");
		return;
	}
	printf("������ ����� ��ȣ : ");
	int c;
	scanf("%d", &c);
	getchar();
	if (c > *n || c < 1)
		printf("�׷��� �����ϴ�");
	else
	{
		if (*n != c)
			for (int i = --c; i < *n - 1; ++i)
				a[i] = a[i + 1];
		(*n)--;
		printf("�������ϴ�");
	}
	printf("\n\n");
}
int main()
{
	list friend[100];
	int n = 0, t;
	char ct;
	while (1)
	{
		printf("1 : ��Ϻ���, 2 : �߰��ϱ�, 3 : Ž���ϱ�, 4 : �����ϱ�\n�Է� : ");
		scanf("%d", &t);
		getchar();
		if (t == 1)
			view(friend, n);
		else if (t == 2)
			add(friend, &n);
		else if (t == 3)
			search(friend, n);
		else if (t == 4)
			del(friend, &n);
		else
			return 0;
	}
}