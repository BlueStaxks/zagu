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

	list-p는 list_t의 포인터로 정의되었다.
	foobar에 들어가는 매개변수로 ptr은 이 포인터의 포인터 이고 node는 list_t의 위치, 그냥 포인터이다.
	*ptr이 list_t의 포인터 값인 것이다.
	
	list_t의 구조를 보면 link가 1개이므로 단순 연결 리스트이다. (2,4번 아님)

	if문에선 *ptr이 NULL일 때, 즉 비어있을 때 그 부분을 node로 채우고 node가 자기 자신을 다음 노드로 지정하게 함.
	else문에선 node링크를 *ptr링크로 하고 *ptr링크를 node로 하여 *ptr이 가리키는 노드 뒤에 node를 놓고 node뒤에 *ptr이 가리키는 노드의 다음 노드를 둔다. 말 그대로 *ptr 뒤에 node를 넣는 것이다.

	원형 리스트는 마지막 노드가 처음 노드를 가리켜야 하는데 그렇지 않은 것으로 보아 답은 1번이다.

*/