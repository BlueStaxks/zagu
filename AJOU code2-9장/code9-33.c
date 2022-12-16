//void bubble_sort(int A[], int n)
//{
//	int i, j, flag;
//	for (i = n; i > 1; i--) { /* i >= 1 */
//		flag = 0;
//		for (j = 2; j <= i; j++)
//			if (A[j - 1] > A[j])
//			{
//				int temp = A[j - 1];
//				A[j - 1] = A[j];
//				A[j] = temp;
//				flag++;
//			}
//		if (flag == 0) break;
//	}
//}
/*

	이렇게 flag를 두면 이미 정렬된 경우 더이상 작업을 진행하지 않으므로 최악의 경우가 아닌 이상
	더 빨리 작업할 수 있다.

*/
#include <stdio.h>
void bubble_sort(int A[], int n)
{
	int i, j, flag;
	for (i = n; i > 1; --i)
	{
		flag = 0;
		for (j = 1; j < i; ++j)
			if (A[j - 1] > A[j])
			{
				int t = A[j - 1];
				A[j - 1] = A[j];
				A[j] = t;
				flag++;
			}
		if (flag == 0) break;
		for (j = 0; j < n; ++j)
			printf("%d ", A[j]);
		printf("\n\n");
	}
}
int main()
{
	int a[] = { 30,50,10,80,40,60,70,90 };
	bubble_sort(a, 8);
	return 0;
}
/*

	출력하면 과정 나옴

*/