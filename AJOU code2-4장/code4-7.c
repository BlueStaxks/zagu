#include <stdio.h>
struct list_t {
	int data;
	struct list_t* link;
};

typedef struct list_t* list_p;

void foobar(list_p* ptr, struct list_t* node) {
	if (*ptr == NULL) {
		*ptr = node;
		node->link = node;
	}
	else {
		node->link = (*ptr)->link;
		(*ptr)->link = node;
	}
}

/*

	list-p�� list_t�� �����ͷ� ���ǵǾ���.
	foobar�� ���� �Ű������� ptr�� �� �������� ������ �̰� node�� list_t�� ��ġ, �׳� �������̴�.
	*ptr�� list_t�� ������ ���� ���̴�.
	
	list_t�� ������ ���� link�� 1���̹Ƿ� �ܼ� ���� ����Ʈ�̴�. (2,4�� �ƴ�)

	if������ *ptr�� NULL�� ��, �� ������� �� �� �κ��� node�� ä��� node�� �ڱ� �ڽ��� ���� ���� �����ϰ� ��.
	else������ node��ũ�� *ptr��ũ�� �ϰ� *ptr��ũ�� node�� �Ͽ� *ptr�� ����Ű�� ��� �ڿ� node�� ���� node�ڿ� *ptr�� ����Ű�� ����� ���� ��带 �д�. �� �״�� *ptr �ڿ� node�� �ִ� ���̴�.

	���� ����Ʈ�� ������ ��尡 ó�� ��带 �����Ѿ� �ϴµ� �׷��� ���� ������ ���� ���� 1���̴�.

*/