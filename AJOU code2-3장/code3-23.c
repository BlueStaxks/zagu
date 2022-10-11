#include <stdio.h>
int main()
{
	int A[3][4] = { {1,3,5,7},{5,7,9,4},{4,9,5,9} };
	int B[4][3];
	int i, j;
	
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; ++j)
			B[j][i] = A[i][j]; //B가 A의 전치행렬이 됨.

	return 0;
}