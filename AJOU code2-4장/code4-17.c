struct node {
	int key;
	struct node* next;
};

struct node* last;

void insertFront(struct node* p) {
	if ("리스트가 빔")
	{
		last = p;
		p->next = p; //last노드를 p로 함.
	}
	else
	{
		p->next = last->next; //p의 다음은 last의 다음(첫)  //ㄱ
		last->next = p;		  //last의 다음은 p			 //ㄴ
	}
}

//1번이 답.