/*

	left와 right를 서로 바꾸고 있다.
	바꾼 뒤 left를 먼저 가지만 가기 전에 바꾸고 가기 때문에 전위 순회라고 할 수 있고 바뀐 left는 원래 right이므로
	탐색 -> right -> left순으로 순회한다.

	결국 트리가 루트 노드를 기준으로 뒤집힌다.

	1번의 의미가 그나마 맞아 보인다.

	아래의 코드를 돌려보면 A를 기준으로 뒤집힌 것이 되는 것을 볼 수 있다.
	트리는 18번의 트리를 사용했다.

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