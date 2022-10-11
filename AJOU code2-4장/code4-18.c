/*

	B->right->left = B->left
	B->left->right = B->right

	A->right = C
	C->left = A

	A->right = A->right->right
	B->right->left = B->left

	C->left->right = B->right  <<<< 얘는 아무 의미없는 입력임
	C->left = B->left 이러면 A다음에 C인 것이 적용 안됨

	4번이 답.

*/