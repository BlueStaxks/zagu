/*

	first 노드 다음에 tmp가 나오도록 하고 tmp다음엔 second가 나오도록 하면 된다.
	그러려면
	
	tmp.link=&second;  (tmp의 링크를 second주소로 바꿈)
	근데 여기서 &second는 first.link와 같다(둘이 이미 연결되어 있으므로)
	first.link=&tmp;   (first의 링크를 tmp주소로 바꿈)

	2번이 답.

*/