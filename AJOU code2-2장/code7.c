#include <stdio.h>
int main()
{
	struct employee {
		char name[20];
	};

	struct employee Lee, Hong, Kim[3];
	struct employee* sp;

	/*1��*/
	sp = Kim; //Kim�� �׳� ���� Kim�迭�� ù �׸��� ��ġ�� �ǹǷ� �� ���� ��ȿ�ϴ�.

	/*2��*/
	sp = Lee; //������ ���� �ʴ´�.

	/*3��*/
	Lee = Kim; //������ ���� �ʴ´�.

	/*4��*/
	Kim[0] = Kim[3]; //Kim[3]�� �߸��� �����̴�.

	/*5��*/
	sp = Kim[1]; //������ ���� �ʴ´�.

	//1���� ������
	return 0;
}