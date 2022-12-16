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

	�̷��� flag�� �θ� �̹� ���ĵ� ��� ���̻� �۾��� �������� �����Ƿ� �־��� ��찡 �ƴ� �̻�
	�� ���� �۾��� �� �ִ�.

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

	����ϸ� ���� ����

*/