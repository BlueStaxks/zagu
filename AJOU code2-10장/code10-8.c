/*

	ABCDEFGHIJKLMNO  15개
	       .

	H와 가장 먼저 비교된다. 작으므로 start=A, end=G, mid=D

	D와 비교해도 작으므로 start=A, end=C, mid=B

	B와 비교하면 크므로 start=C, end=C, mid=C

	mid와 C가 같으므로 탐색 끝.

	4번이 답.

*/