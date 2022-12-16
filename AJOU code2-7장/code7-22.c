/*

	이진 탐색 트리에는 한 노드를 기준으로 left엔 노드의 키값보다 작은 값이, right엔 큰 값이 들어가야 한다.
	이것이 마지막 레벨에서 정렬 상태를 의미하진 않지만 최소와 최대값 만큼은 확실히 확보된다.

	가능한 왼쪽 노드로 들어가다보면 최소 키값의 노드가 나올 것이다.

	왼쪽으로 갈 수 있으면 최대한 가고 더이상 못가면 그 상태를 return 하면 되므로

	ㄱ엔 return T;
	ㄴ엔 return FindMin(T->left);

	3번이 답.

*/