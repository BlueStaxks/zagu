struct node {
	int key;
	struct node* next;
};

struct node* last;

void insertFront(struct node* p) {
	if ("����Ʈ�� ��")
	{
		last = p;
		p->next = p; //last��带 p�� ��.
	}
	else
	{
		p->next = last->next; //p�� ������ last�� ����(ù)  //��
		last->next = p;		  //last�� ������ p			 //��
	}
}

//1���� ��.