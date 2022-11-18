#include <stdio.h>
#include <stdlib.h>
typedef struct Tdata{
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

	A->data = 'A';	B->data = 'B';	C->data = 'C';	D->data = 'D';	E->data = 'E';	F->data = 'F';	G->data = 'G';

	A->left = B;
	A->right = E;

	B->left = C;
	B->right = D;

	C->left = C->right = NULL;
	
	D->left = D->right = NULL;

	E->left = F;
	E->right = NULL;
	
	F->left = NULL;
	F->right = G;
	
	G->left = NULL;
	G->right = NULL;
	

	pre(A);
	printf("\n\n");
	in(A);
	printf("\n\n");
	post(A);
	printf("\n\n");

	return 0;

	//4¹øÀÌ ´ä.
}