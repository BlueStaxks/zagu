#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j, s = 0;
	int a[10][3];
	for (i = 0; i < 10; ++i)
		for(j=0; j<3; ++j)
			a[i][j] = rand() % 101; //�������� ���� �Է�
	
	printf("      �й�     ����    ����    ����     ����           ���\n");
	printf("***********************************************************\n\n");
	for (i = 0; i < 10; ++i, s = 0)
	{
		for (j = 0; j < 3; ++j)
			s += a[i][j];
		printf("\t%d\t%d\t%d\t%d\t%d\t\t%d\n\n", i + 1, a[i][0], a[i][1], a[i][2], s, s / 3);
	}
	return 0;
}