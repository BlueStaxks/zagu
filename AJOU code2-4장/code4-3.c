/*

	그림에 p는 없지만 P가 p라고 가정하고 생각해 본다면

	먼저 for문에서 tmp->link는 결국 p가 되며 끝난다.
	tmp는 P전인 '나' 노드이다.
	
	그리고 tmp->link는 p->link가 되면서 '다'노드가 없는 것이 된다.

	여전히 tmp는 '나' 노드를 가리킨다.

	2번이 답.

*/