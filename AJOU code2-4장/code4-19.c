#include <stdio.h>
#include <stdlib.h>
struct node {
	int key;
	struct node* prev;
	struct node* next;
};

struct node* head = NULL;

void insertDoubleList(int ikey) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("Memory allocation is failed. \n");
		exit(1);
	}
	temp->key = ikey;
	temp->prev = NULL; //temp�� �߰��� ����̰� �� �տ� ���Ƿ� �� �տ� ���� ����� ��.
	if (head == NULL)
		temp->next = NULL; //temp���� NULL�ΰ� ������ next�� NULL�ΰɷ� �� ������.
	else
	{
		temp->next = head; //temp������ head�� �� �˷�����.
		head->prev = temp;
	}
	head = temp;
}

//2���� ��.