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
	A->right = NULL;

	B->left = C;
	B->right = D;

	C->left = E;
	C->right = F;

	D->left = G;
	D->right = H;

	E->left = NULL;
	E->right = I;

	F->left = NULL;
	F->right = J;

	G->left = NULL;
	G->right = NULL;

	H->left = K;
	H->right = L;

	I->left = NULL;
	I->right = NULL;

	J->left = NULL;
	J->right = NULL;

	K->left = NULL;
	K->right = NULL;

	L->left = NULL;
	L->right = NULL;


	post(A);
	printf("\n\n");

	return 0;

	//I E J F C G K L H D B A
	//2¹øÀÌ ´ä.
}