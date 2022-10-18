/*

	큐는 위로 넣고 아래로 나오는 형식이다.

	1.
	새로 원소를 추가할 때 D 뒤에 넣어야 한다. 그러려면 D로 가야 하기 때문에 큐 전체를 돌아야 한다.

	삭제하려면 A를 삭제해야 하는데 D 다음에 B가 오게 만들기 위해 또 큐 전체를 돌아야 한다.

	2.
	새로 원소를 추가하면 포인터 다음에 넣으면 되기 때문에 바로 할 수 있다.

	원소를 삭제하려면 A의 링크를 D의 링크에 넣으면 되기 때문에 바로 할 수 있다.

	3.
	새로 원소를 추가하면 D 뒤에 들어가는데 A의 링크를 변경하기 위해서 큐 전체를 돌아야 한다.

	삭제하려면 A를 삭제해야 하는데 A까지 가기 위해 또 큐 전체를 돌아야 한다.

	4.
	새로 원소를 추가하면 포인터 뒤에 바로 넣으면 된다.

	삭제하려면 포인터를 마지막에 B에 맞춰야 하기 때문에 큐 전체를 돌아야 한다.


	2번이 제일 효율적이다. (포인터가 마지막 노드를 가리키는 원형 리스트 구조)

*/