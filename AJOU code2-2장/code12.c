#include <stdio.h>
public static int xxx(int n);
{
	if (n == 0)	return 4;
	return 1 + xxx(n - 1);
}
int main()
{
	printf("%d ", xxx(5));
	/*
	
	������ �Ұ��������� ����Լ���� �����ϰ� �����غ���
	ó���� 5�� ���� xxx(4) + 1�� �ȴ�.
	4�� ���� �� xxx(3) + 1, ~~~ �̰�
	xxx(0)�̵Ǹ� 4�� �ǹǷ� 4 + 1 + 1 + 1 + 1 + 1
						 0   1   2   3   4   5
	�� 9�� ���´�.

	4���� ���̴�.
	*/
	return 0;
}