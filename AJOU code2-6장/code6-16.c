/*

	각 명령을 따라가며 front와 rear를 체크해 보자

		push(A), push(B), pop(), push(C), pop(), pop(), push(D), push(E), pop(), push(F), pop()
	0           1       2      1         2      1      0        1        2      1       2       1
	front=0
	rear=0
			 front=0
			 rear=1
				      front=0
					  rear=2
					         front=1
							 rear=2
							           front=1
									   rear=3
											 front=2
											 rear=3
											        front=3
													rear=3
													        front=3
															rear=4
																	  front=3
																	  rear=5 여기서 인덱스를 초과한다.
																			 E를 삽입할 수 없다.
																			 
	D가 삽입된 순간 큐가 포화되어 더 이상 삽입을 할 수 없다.		
	
*/