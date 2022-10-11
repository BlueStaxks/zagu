#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	int data;
	struct _node* next;
} node;

node* head;
node* tail;

void init_list(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail; //처음엔 둘 밖에 없음
	tail->next = tail; //끝은 NULL이 아니라 자기 자신
}

node* ordered_insert(int k) {
	node* p = head;
	node* i = (node*)malloc(sizeof(node));
	i->data = k;
	if (p->next == tail) //암것도 없음
	{
		head->next = i;
		i->next = tail;
		return i;
	}
	while (p != tail)
	{
		if (p->next->data >= k) //이러면 k는 그 전에 들가야됨
		{
			i->next = p->next;
			p->next = i;
			return i;
		}
		if (p->next == tail) //위에서 안끝나고 여기까지 왔으면 k가 젤 크단 뜻
		{
			i->next = tail;
			p->next = i;
			return i;
		}
		p = p->next;
	}
}
node* print_list(node* t) {
	node* p = t; //t값을 오염시키면 안 됨.
	while (p != tail)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
	return p;
}
int delete_node(int k) {
	node* p = head;
	while (p != tail)
	{
		if (p->next->data == k)
		{
			p->next = p->next->next;
			printf("지웠음!!\n\n");
			return k;
		}
		p = p->next;
	}
	printf("그런거 읎다\n\n");
	return -1;
}

//int _tmain(int argc, _TCHAR* argv[]) {
int main() {
	node* t;

	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);

	printf("\nInitial Linked list is ");
	print_list(head->next);

	delete_node(8);
	print_list(head->next);

	return 0;
}