/*

	else if에서 T의 값이 k이하일 경우를 감싸고 있다.
	이 경우 T의 오른쪽으로 넘어가게 되어있다.

	만약 else if를 지나치고 온다면 T의 값이 k보다 크다는 뜻이다.
	이때 T의 왼쪽 또한 k보다 클 수 있으므로 numGreaterThan(T.left, k)의 값과 T.right.numDesc + 1을 리턴하면 된다.

	4번이 답.

*/