/*

	K[1:2, 1:3, 1:2] 는 K[2][3][2]인데 각각 1,1,1부터 인덱스가 시작한다는 뜻이다.
	K 전체에서 9번 째 원소는 K[1][1][0]에 있을 것이다.
	그런데 각각 1,1,1부터 시작하므로 K(2,2,1)이 답이다.

	3번이 답.

*/
#include <stdio.h>
int main()
{
	//int K[2][3][2];
	int c = 1, i,j,l;
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 3; ++j)
			for (l = 0; l < 2; ++l)
				printf("%d\tK[%d][%d][%d]\n", c++, i, j, l);
	return 0;
}