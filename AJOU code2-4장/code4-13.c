struct list_node {
	char data;
	struct list_node* linkl;
};

typedef struct list_node* list_pointer;

int CListLength(list_pointer ptr) {
	list_pointer temp;
	int count = 0;
	if (ptr) { //ptr�� NULL�̸� ������ ���ϹǷ� count�� 0�� ���·� return�ž� ��.
		temp = ptr;
		do {
			count++;
		} while (); //���� ��ȭ�� �־�� �ϹǷ� 4���� temp->link == ptr�� �������� ����
					//temp�� �����ؾ� �ϹǷ� temp=temp->link�� �־�� �ϰ�
					//temp�� ptr�� �ƴϿ��� �ϴ� ������ �ʿ���. ���� ����Ʈ�̱� ������ temp�� ptr�� ���ٸ� �� ���� ����.
	}
	return count;

	//2���� ��.
}