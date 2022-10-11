/*

	먼저 빈 스택에 A가 들어가고 B가 또 들어간다.
	그 다음 연산자 -가 나오므로 A-B를 연산하고 A,B를 모두 pop한 뒤 다시 스택에 넣어서
	결국 스택엔 A-B의 결과만 하나 들어있게 된다.

	그 상태에서 C가 push된다.
	그리고 -가 또 나오므로 A-B에서 C를 뺀 값이 스택에 push되는데 이때 기존의 2 값은 모두 pop된다.

	또 D가 들어오고 +가 들어오므로
	(A-B) - C + D 가 최종 값이 되고 이 값 하나만 스택에 남게 된다.

*/