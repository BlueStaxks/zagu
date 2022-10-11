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
		printf("아무것도 없습니당");
	else
		for (int i = 0; i < n; ++i)
			printf("\t%d.\t%s\t%s\t%s\t%s\n", i + 1, a[i].name, a[i].number, a[i].address, a[i].birthday);
	printf("\n\n");
}
void add(list a[], int* n)
{
	char c;
	list lt;
	printf("이름 : ");
	scanf("%[^\n]s", lt.name);
	scanf("%c", &c);
	printf("전화번호 : ");
	scanf("%[^\n]s", lt.number);
	scanf("%c", &c);
	printf("주소 : ");
	scanf("%[^\n]s", lt.address);
	scanf("%c", &c);
	printf("생일 : ");
	scanf("%[^\n]s", lt.birthday);
	scanf("%c", &c);
	a[(*n)++] = lt;
	printf("추가되었습니당\n\n");
}
void search(list a[], int n)
{
	char c[1000];
	printf("찾을 내용 입력 : ");
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
		printf("아무것도 없습니당\n");
	printf("\n\n");
}
void del(list a[], int* n)
{
	if (!(*n))
	{
		printf("지울 게 없습니당\n\n");
		return;
	}
	printf("삭제할 목록의 번호 : ");
	int c;
	scanf("%d", &c);
	getchar();
	if (c > *n || c < 1)
		printf("그런거 없습니당");
	else
	{
		if (*n != c)
			for (int i = --c; i < *n - 1; ++i)
				a[i] = a[i + 1];
		(*n)--;
		printf("지웠습니당");
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
		printf("1 : 목록보기, 2 : 추가하기, 3 : 탐색하기, 4 : 삭제하기\n입력 : ");
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