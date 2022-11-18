/*

	left�� right�� ���� �ٲٰ� �ִ�.
	�ٲ� �� left�� ���� ������ ���� ���� �ٲٰ� ���� ������ ���� ��ȸ��� �� �� �ְ� �ٲ� left�� ���� right�̹Ƿ�
	Ž�� -> right -> left������ ��ȸ�Ѵ�.

	�ᱹ Ʈ���� ��Ʈ ��带 �������� ��������.

	1���� �ǹ̰� �׳��� �¾� ���δ�.

	�Ʒ��� �ڵ带 �������� A�� �������� ������ ���� �Ǵ� ���� �� �� �ִ�.
	Ʈ���� 18���� Ʈ���� ����ߴ�.

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Tdata {
	char data;
	int index;
	struct Tdata* left;
	struct Tdata* right;
}Tdata;

void pre(Tdata* k)
{
	if (k != NULL)
	{
		printf("%c ", k->data);
		pre(k->left);
		pre(k->right);
	}
}
void in(Tdata* k)
{
	if (k != NULL)
	{
		in(k->left);
		printf("%c ", k->data);
		in(k->right);
	}
}
void post(Tdata* k)
{
	if (k != NULL)
	{
		post(k->left);
		post(k->right);
		printf("%c ", k->data);
	}
}
void DOTHING(Tdata* k)
{
	Tdata* t;
	if (k == NULL)	return;
	t = k->right;
	k->right = k->left;
	k->left = t;
	DOTHING(k->left);
	DOTHING(k->right);
}
int main()
{
	Tdata* A = (Tdata*)malloc(sizeof(Tdata));
	Tdata* B = (Tdata*)malloc(sizeof(Tdata));
	Tdata* C = (Tdata*)malloc(sizeof(Tdata));
	Tdata* D = (Tdata*)malloc(sizeof(Tdata));
	Tdata* E = (Tdata*)malloc(sizeof(Tdata));
	Tdata* F = (Tdata*)malloc(sizeof(Tdata));
	Tdata* G = (Tdata*)malloc(sizeof(Tdata));
	Tdata* H = (Tdata*)malloc(sizeof(Tdata));
	Tdata* I = (Tdata*)malloc(sizeof(Tdata));
	Tdata* J = (Tdata*)malloc(sizeof(Tdata));
	Tdata* K = (Tdata*)malloc(sizeof(Tdata));
	Tdata* L = (Tdata*)malloc(sizeof(Tdata));

	A->data = 'A';	B->data = 'B';	C->data = 'C';	D->data = 'D';	E->data = 'E';	F->data = 'F';	G->data = 'G';	H->data = 'H';	I->data = 'I';
	J->data = 'J';	K->data = 'K';	L->data = 'L';

	A->left = B;
	A->right = C;

	B->left = D;
	B->right = E;

	C->left = F;
	C->right = G;

	D->left = NULL;
	D->right = NULL;

	E->left = H;
	E->right = NULL;

	F->left = NULL;
	F->right = I;

	G->left = NULL;
	G->right = NULL;

	H->left = NULL;
	H->right = NULL;

	I->left = J;
	I->right = NULL;

	J->left = NULL;
	J->right = NULL;

	K->left = NULL;
	K->right = NULL;

	L->left = NULL;
	L->right = NULL;

	DOTHING(A);

	//pre(A); //A B D E H C F I J G
	//printf("\n\n");
	printf("A :  %c,%c\n", A->left != NULL ? A->left->data : '*', A->right != NULL ? A->right->data : '*');
	printf("B :  %c,%c\n", B->left != NULL ? B->left->data : '*', B->right != NULL ? B->right->data : '*');
	printf("C :  %c,%c\n", C->left != NULL ? C->left->data : '*', C->right != NULL ? C->right->data : '*');
	printf("D :  %c,%c\n", D->left != NULL ? D->left->data : '*', D->right != NULL ? D->right->data : '*');
	printf("E :  %c,%c\n", E->left != NULL ? E->left->data : '*', E->right != NULL ? E->right->data : '*');
	printf("F :  %c,%c\n", F->left != NULL ? F->left->data : '*', F->right != NULL ? F->right->data : '*');
	printf("G :  %c,%c\n", G->left != NULL ? G->left->data : '*', G->right != NULL ? G->right->data : '*');
	printf("H :  %c,%c\n", H->left != NULL ? H->left->data : '*', H->right != NULL ? H->right->data : '*');
	printf("I :  %c,%c\n", I->left != NULL ? I->left->data : '*', I->right != NULL ? I->right->data : '*');
	printf("J :  %c,%c\n", J->left != NULL ? J->left->data : '*', J->right != NULL ? J->right->data : '*');

	return 0;
}