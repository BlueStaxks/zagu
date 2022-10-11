#include <stdio.h>
void Minima(int* R, int* A)
{
	int i, j, c = 0;
	for (i = 0; i < R[0]; ++i)
		for (j = 0; j < R[1]; ++j)
		{
			if (A[R[1] * i + j])
			{
				c++;
				int p = c * 3;
				R[p] = i;
				R[p + 1] = j;
				R[p + 2] = A[R[1] * i + j];
			}
		}
	R[2] = c;
}
int main()
{
	int A[7][4] = { {0,0,0,9},{0,1,0,0},{0,0,0,0},{0,0,7,0},{0,0,0,0},{3,0,0,0},{0,0,0,0} }; //예시 배열

	int R[sizeof(A)/sizeof(int)][3];
	R[0][0] = sizeof(A) / sizeof(A[0]);
	R[0][1] = sizeof(A[0]) / sizeof(int);

	Minima(R, A); //2차원 배열도 결국 1차원 배열의 변형임을 이용함

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
			printf("%d ", R[i][j]);
		printf("\n");
	}

	return 0;
}