//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTEX 7
//#define INF 999
//int g10[MAX_VERTEX][MAX_VERTEX] = {
//	{ 0, 3, 17, 6, INF, INF, INF},
//	{ 3, 0, INF, 5, INF, INF, 12 },
//	{ 17, INF, 0, INF, 10, 8, INF},
//	{ 6, 5, INF, 0, 9, INF, INF},
//	{INF, INF, 10, 9, 0, 4, 2 },
//	{INF, INF, 8, INF, 4, 0, 14 },
//	{INF, 12, INF, INF, 2, 14, 0 }
//};
//typedef struct {
//	int s;
//	int e;
//	int w;
//} line;
//typedef struct Node {
//	int data;
//	struct Node* left;
//	struct Node* right;
//} Node;
//Node* root[MAX_VERTEX] = NULL;
//int rootp = -1;
//
//line r[1000]; //line 총집합
//line tr[100]; //최대 힙에서 제외되지만 남아있어야 하는 간선
//int par[MAX_VERTEX];
//int p = 0, trp = -1, cp = 0;
//void insMA(line k)
//{
//	if (p == 999)	return;
//	p++;
//	int i = p;
//	while (!(i == 1 || k.w <= r[i / 2].w))
//	{
//		r[i] = r[i / 2];
//		i = i >> 1;
//	}
//	r[i] = k;
//	return;
//}
//void delMA()
//{
//	if (!p)	return;
//	line k = r[1];
//	line t = r[p];
//	p--;
//	int i = 1;
//	int j = 2;
//	while (j <= p)
//	{
//		if (j < p && r[j].w < r[j + 1].w)
//			j++;
//		if (t.w >= r[j].w)	break;
//		r[i] = r[j];
//		i = j;
//		j = j << 1;
//	}
//	r[i] = t;
//	return;
//}
//void insMI(line k)
//{
//	if (p == 999)	return;
//	p++;
//	int i = p;
//	while (!(i == 1 || k.w >= r[i / 2].w))
//	{
//		r[i] = r[i / 2];
//		i = i >> 1;
//	}
//	r[i] = k;
//	return;
//}
//void delMI()
//{
//	if (!p)	return;
//	line k = r[1];
//	line t = r[p];
//	p--;
//	int i = 1;
//	int j = 2;
//	while (j <= p)
//	{
//		if (j < p && r[j].w > r[j + 1].w)
//			j++;
//		if (t.w <= r[j].w)	break;
//		r[i] = r[j];
//		i = j;
//		j = j << 1;
//	}
//	r[i] = t;
//	return;
//}
//int check1() //DFS
//{
//	int hb[MAX_VERTEX] = { 0 };
//	int tc = MAX_VERTEX - 1;
//	int st[1000] = { 0 };
//	int sp = 0, i;
//	hb[0] = 1;
//	while (sp >= 0)
//	{
//		int t = st[sp--];
//		for (i = 2; i <= p; ++i)
//		{
//			if (r[i].s == t && !hb[r[i].e])
//			{
//				st[++sp] = r[i].e;
//				hb[r[i].e] = 1;
//				tc--;
//			}
//			if (r[i].e == t && !hb[r[i].s])
//			{
//				st[++sp] = r[i].s;
//				hb[r[i].s] = 1;
//				tc--;
//			}
//		}
//		for (i = 0; i <= trp; ++i)
//		{
//			if (tr[i].s == t && !hb[tr[i].e])
//			{
//				st[++sp] = tr[i].e;
//				hb[tr[i].e] = 1;
//				tc--;
//			}
//			if (tr[i].e == t && !hb[tr[i].s])
//			{
//				st[++sp] = r[i].s;
//				hb[r[i].s] = 1;
//				tc--;
//			}
//		}
//	}
//	return tc; //tc가 남아있으면 지우면 안되는 간선인 것
//}
//int overlapC(int v1)
//{
//	Node* t = root;
//	while (t != NULL)
//	{
//		if (t->data < v1)
//		{
//			if (t->right == NULL)
//			{
//				Node* t1 = (Node*)malloc(sizeof(Node)); //처음 보는 애면 추가
//				t1->data = v1;
//				t1->left = NULL;
//				t1->right = NULL;
//				t->right = t1;
//				return 0;
//			}
//			t = t->right;
//		}
//		else if (t->data > v1)
//		{
//			if (t->left == NULL)
//			{
//				Node* t1 = (Node*)malloc(sizeof(Node)); //처음 보는 애면 추가
//				t1->data = v1;
//				t1->left = NULL;
//				t1->right = NULL;
//				t->left = t1;
//				return 0;
//			}
//			t = t->left;
//		}
//		else //중복
//			return 1;
//	}
//}
//int onlyoverlap(Node* k, int v1)
//{
//	Node* t = k;
//	while (t != NULL)
//	{
//		if (t->data < v1)
//		{
//			if (t->right == NULL)	return 0;
//			t = t->right;
//		}
//		else if (t->data > v1)
//		{
//			if (t->left = NULL)	return 0;
//			t = t->left;
//		}
//		else   return 1;
//	}
//	return 0;
//}
//int check2() //이진 탐색 트리를 사용해 set 구현
//{
//	if (rootp == -1) //set 처음 생성
//	{
//		Node* t1 = (Node*)malloc(sizeof(Node));
//		t1->data = r[1].s;
//		Node* t2 = (Node*)malloc(sizeof(Node));
//		t2->data = r[1].e;
//		if (r[1].s < r[1].e)
//		{
//			t1->left = NULL;
//			t1->right = t2;
//		}
//		else
//		{
//			t1->left = t2;
//			t1->right = NULL;
//		}
//		t2->left = NULL;
//		t2->right = NULL;
//		root[++rootp] = t1;
//		return 0;
//	}
//	for (int i = 0; i <= rootp; ++i)
//	{
//		int k = onlyoverlap(root[i], r[1].s) + onlyoverlap(root[i], r[1].e);
//		if (k == 0) //하나도 안겹친다 -> 새로운 트리 필요
//		{
//			rootp++;
//		}
//
//	}
//	return (overlapC(r[1].s) + overlapC(r[1].e)) == 2;
//}
//void func1()
//{
//	int i, j;
//	p = 0, trp = -1, cp = 0;
//	for (i = 0; i < MAX_VERTEX; ++i)
//		for (j = i + 1; j < MAX_VERTEX; ++j)
//			if (g10[i][j] != INF)
//			{
//				line t = { i,j,g10[i][j] };
//				insMA(t); //최대 힙에 추가
//			}
//	printf("Heap[1~%d]: ", p);
//	for (i = 1; i <= p; ++i)
//		printf("[%d] ", r[i].w);
//	printf("\n   ...  deleting the largest edge ...\n");
//	while (p + cp >= MAX_VERTEX)
//	{
//		if (check1()) //0이 나오면 지워도 됨
//		{
//			line t = r[1];
//			printf("+ Edge (%d %d)[%2d] not deleted.\n", r[1].s, r[1].e, r[1].w);
//			cp++;
//			tr[++trp] = t;
//		}
//		else
//			printf("- Edge (%d %d)[%2d] deleted.\n", r[1].s, r[1].e, r[1].w);
//		delMA();
//	}
//	printf("Heap[1~%d]: ", p);
//	for (i = 1; i <= p; ++i)
//		printf("[%d] ", r[i].w);
//	printf("\n\n");
//}
//void func2()
//{
//	int i, j;
//	p = 0, trp = -1, cp = 0;
//	for (i = 0; i < MAX_VERTEX; ++i)
//		par[i] = i;
//	for (i = 0; i < MAX_VERTEX; ++i)
//		for (j = i + 1; j < MAX_VERTEX; ++j)
//			if (g10[i][j] != INF)
//			{
//				line t = { i,j,g10[i][j] };
//				insMI(t); //최소 힙에 추가
//			}
//	printf("Heap[1~%d]: ", p);
//	for (i = 1; i <= p; ++i)
//		printf("[%d] ", r[i].w);
//	printf("\n   ... inserting the smallest edge ...\n");
//	while (cp < MAX_VERTEX)
//	{
//		if (check2()) //0이 나오면 중복 아님
//		{
//			line t = r[1];
//			printf("- Edge (%d %d)[%2d] not inserted.\n", r[1].s, r[1].e, r[1].w);
//			tr[++trp] = t;
//		}
//		else
//		{
//			printf("+ Edge (%d %d)[%2d] inserted.\n", r[1].s, r[1].e, r[1].w);
//			cp++;
//		}
//		delMI();
//	}
//	printf("Heap[1~%d]: ", p);
//	for (i = 1; i <= p; ++i)
//		printf("[%d] ", r[i].w);
//	printf("\n\n");
//}
//
//int main()
//{
//	printf("*** MST: Kruskal I Algorithm ***\n");
//	func1();
//	printf("*** MST: Kruskal II Algorithm ***\n");
//	func2();
//
//}