struct list_node {
	char data;
	struct list_node* linkl;
};

typedef struct list_node* list_pointer;

int CListLength(list_pointer ptr) {
	list_pointer temp;
	int count = 0;
	if (ptr) { //ptr이 NULL이면 시작을 못하므로 count가 0인 상태로 return돼야 함.
		temp = ptr;
		do {
			count++;
		} while (); //뭔가 변화가 있어야 하므로 4번의 temp->link == ptr은 적절하지 않음
					//temp가 전진해야 하므로 temp=temp->link가 있어야 하고
					//temp가 ptr이 아니여야 하는 조건이 필요함. 원형 리스트이기 때문에 temp가 ptr과 같다면 한 바퀴 돈것.
	}
	return count;

	//2번이 답.
}