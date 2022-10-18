/*

	front = 0, rear = 2

	0 1 2 3 4 5

	# A B # # #
	--가
	# A B C # #    //rear = 3
	--나
	# # # C # #    //front = 2
	--다
	# # # # # #    //front = 3
	--라
	# # # # D #    //rear = 4
	--마
	# # # # D E    //rear = 5
	--바
	F # # # D E    //rear = 6%6 == 0

	2번이 답.

*/