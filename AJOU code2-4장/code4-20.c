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
	head->next = tail; //ó���� �� �ۿ� ����
	tail->next = tail; //���� NULL�� �ƴ϶� �ڱ� �ڽ�
}

node* ordered_insert(int k) {
	node* p = head;
	node* i = (node*)malloc(sizeof(node));
	i->data = k;
	if (p->next == tail) //�ϰ͵� ����
	{
		head->next = i;
		i->next = tail;
		return i;
	}
	while (p != tail)
	{
		if (p->next->data >= k) //�̷��� k�� �� ���� �鰡�ߵ�
		{
			i->next = p->next;
			p->next = i;
			return i;
		}
		if (p->next == tail) //������ �ȳ����� ������� ������ k�� �� ũ�� ��
		{
			i->next = tail;
			p->next = i;
			return i;
		}
		p = p->next;
	}
}
node* print_list(node* t) {
	node* p = t; //t���� ������Ű�� �� ��.
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
			printf("������!!\n\n");
			return k;
		}
		p = p->next;
	}
	printf("�׷��� ����\n\n");
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