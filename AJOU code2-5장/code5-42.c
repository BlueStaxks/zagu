/*

	피보니치 수열을 재귀로 구현했다고 가정해보자.
	fibo(n) = fibo(n-1) + fibo(n-2) 라는 식이 있다.
	여기서 fibo(n-1)의 계산 결과를 가지고 와서 이 식을 계산해야 한다.
	그러므로 원래 해야하는 메인 계산을 위해 잠시 딴 곳으로 갔다 오는 것과 같으므로 LIFO구조인 스택을 사용하면 좋다.
	그러면 fibo(n-1)이 스택에 추가되었다가 연산이 끝나면 pop되면서 자연스럽게 메인 계산이 진행될 수 있다.

*/