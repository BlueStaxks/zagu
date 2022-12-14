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


	pre(A); //A B D E H C F I J G
	printf("\n\n");
	in(A);  //D B H E A F J I C G

	return 0;
			//  o   o       o   o
	// 4회 같다.

	// 2번이 답.
}