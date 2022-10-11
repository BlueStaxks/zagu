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
	temp->prev = NULL; //temp는 추가될 노드이고 맨 앞에 들어가므로 그 앞엔 뭐가 없어야 함.
	if (head == NULL)
		temp->next = NULL; //temp앞이 NULL인건 했으니 next도 NULL인걸로 할 차례임.
	else
	{
		temp->next = head; //temp다음이 head인 걸 알려야함.
		head->prev = temp;
	}
	head = temp;
}

//2번이 답.