#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 7
#define INF 999
int g10[MAX_VERTEX][MAX_VERTEX] = {
	{ 0, 3, 17, 6, INF, INF, INF},
	{ 3, 0, INF, 5, INF, INF, 12 },
	{ 17, INF, 0, INF, 10, 8, INF},
	{ 6, 5, INF, 0, 9, INF, INF},
	{INF, INF, 10, 9, 0, 4, 2 },
	{INF, INF, 8, INF, 4, 0, 14 },
	{INF, 12, INF, INF, 2, 14, 0 }
};
typedef struct {
	int s;
	int e;
	int w;
} line;
typedef struct Node {
	line data;
	struct Node* link;
}Node;

line r[1000]; //line 총집합 (힙 전용)
line tr[100]; //최대 힙에서 제외되지만 남아있어야 하는 간선
int p = 0, trp = -1, cp = 0;

void insMA(line k)
{
	if (p == 999)	return;
	p++;
	int i = p;
	while (!(i == 1 || k.w <= r[i / 2].w))
	{
		r[i] = r[i / 2];
		i = i >> 1;
	}
	r[i] = k;
	return;
}
void delMA()
{
	if (!p)	return;
	line k = r[1];
	line t = r[p];
	p--;
	int i = 1;
	int j = 2;
	while (j <= p)
	{
		if (j < p && r[j].w < r[j + 1].w)
			j++;
		if (t.w >= r[j].w)	break;
		r[i] = r[j];
		i = j;
		j = j << 1;
	}
	r[i] = t;
	return;
}

void insMI(line k)
{
	if (p == 999)	return;
	p++;
	int i = p;
	while (!(i == 1 || k.w >= r[i / 2].w))
	{
		r[i] = r[i / 2];
		i = i >> 1;
	}
	r[i] = k;
	return;
}
void delMI()
{
	if (!p)	return;
	line k = r[1];
	line t = r[p];
	p--;
	int i = 1;
	int j = 2;
	while (j <= p)
	{
		if (j < p && r[j].w > r[j + 1].w)
			j++;
		if (t.w <= r[j].w)	break;
		r[i] = r[j];
		i = j;
		j = j << 1;
	}
	r[i] = t;
	return;
}

typedef struct {
	Node* front, * rear;
}Queue;
void initQ(Queue* q)
{
	q->front = q->rear = NULL;
}
bool is_emptyQ(Queue* q)
{
	return (q->front == NULL);
}
void pushQ(Queue* q, line data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL; // rear부분 즉 큐의 마지막에 들어가므로 새로운 노드의 링크부분은 NULL
	if (is_emptyQ(q))
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->link = temp;
		q->rear = temp;
	}
	p++;
}
line popQ(Queue* q)
{
	if (!is_emptyQ(q))
	{
		Node* temp = q->front;
		line data = temp->data;
		q->front = temp->link;
		if (q->front == NULL) // 공백상태
			q->rear = NULL;
		free(temp);
		return data;
	}
	exit(1);
}

int check1() //DFS
{
	int hb[MAX_VERTEX] = { 0 };
	int tc = MAX_VERTEX - 1;
	int st[1000] = { 0 }; //배열로 스택 구현. 스택이니까 DFS
	int sp = 0, i;
	hb[0] = 1;
	while (sp >= 0)
	{
		int t = st[sp--];
		for (i = 2; i <= p; ++i)
		{
			if (r[i].s == t && !hb[r[i].e])
			{
				st[++sp] = r[i].e;
				hb[r[i].e] = 1;
				tc--;
			}
			if (r[i].e == t && !hb[r[i].s])
			{
				st[++sp] = r[i].s;
				hb[r[i].s] = 1;
				tc--;
			}
		}
		for (i = 0; i <= trp; ++i)
		{
			if (tr[i].s == t && !hb[tr[i].e])
			{
				st[++sp] = tr[i].e;
				hb[tr[i].e] = 1;
				tc--;
			}
			if (tr[i].e == t && !hb[tr[i].s])
			{
				st[++sp] = r[i].s;
				hb[r[i].s] = 1;
				tc--;
			}
		}
	}
	return tc; //tc가 남아있으면 지우면 안되는 간선인 것
}

int par[MAX_VERTEX * MAX_VERTEX]; //set용
int getPar(int v)
{
	if (par[v] == v)	return v;
	return par[v] = getPar(par[v]);
}
void tie(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	if (a < b)
		par[b] = a;
	else
		par[a] = b;
}
int check2() //이진 탐색 트리를 사용해 set 구현
{
	if (getPar(r[1].s) == getPar(r[1].e))	return 1; //바로 그냥 부모가 같아버리면 사이클
	tie(r[1].s, r[1].e); //그리고 묶기
	return 0; //배열로 set 구현
}

void func1()
{
	int i, j;
	p = 0, trp = -1, cp = 0;
	for (i = 0; i < MAX_VERTEX; ++i)
		for (j = i + 1; j < MAX_VERTEX; ++j)
			if (g10[i][j] != INF)
			{
				line t = { i,j,g10[i][j] };
				insMA(t); //최대 힙에 추가
			}
	printf("Heap[1~%d]: ", p);
	for (i = 1; i <= p; ++i)
		printf("[%d] ", r[i].w);
	printf("\n   ...  deleting the largest edge ...\n");
	while (p + cp >= MAX_VERTEX)
	{
		if (check1()) //0이 나오면 지워도 됨
		{
			line t = r[1];
			printf("+ Edge (%d %d)[%2d] not deleted.\n", r[1].s, r[1].e, r[1].w);
			cp++;
			tr[++trp] = t; //근데 버리면 안되고 들고 있긴 해야됨. 남겨야 해도 힙에선 지워야 하기 때문
		}
		else
			printf("- Edge (%d %d)[%2d] deleted.\n", r[1].s, r[1].e, r[1].w);
		delMA();
	}
	printf("Heap[1~%d]: ", p);
	for (i = 1; i <= p; ++i)
		printf("[%d] ", r[i].w);
	printf("\n\n");
}
void func2()
{
	int i, j;
	p = 0, cp = 0;
	for (i = 0; i < MAX_VERTEX; ++i) //부모 찾기 초기화
		par[i] = i;
	for (i = 0; i < MAX_VERTEX; ++i)
		for (j = i + 1; j < MAX_VERTEX; ++j)
			if (g10[i][j] != INF)
			{
				line t = { i,j,g10[i][j] };
				insMI(t); //최소 힙에 추가
			}
	printf("Heap[1~%d]: ", p);
	for (i = 1; i <= p; ++i)
		printf("[%d] ", r[i].w);
	printf("\n   ... inserting the smallest edge ...\n");
	while (cp < MAX_VERTEX - 1)
	{
		if (check2()) //0이 나오면 중복 아님
			printf("- Edge (%d %d)[%2d] not inserted.\n", r[1].s, r[1].e, r[1].w);
		else
		{
			printf("+ Edge (%d %d)[%2d] inserted.\n", r[1].s, r[1].e, r[1].w);
			cp++;
		}
		delMI();
	}
	printf("Heap[1~%d]: ", p);
	for (i = 1; i <= p; ++i)
		printf("[%d] ", r[i].w);
	printf("\n\n");
}
void func3()
{
	int i, j, lap = 0;
	p = 0, cp = 1;
	for (i = 0; i < MAX_VERTEX; ++i) //부모 찾기 초기화
		par[i] = i;
	line line_arr[1000];
	for (i = 0; i < MAX_VERTEX; ++i) //간선 제작
		for (j = i + 1; j < MAX_VERTEX; ++j)
			if (g10[i][j] != INF)
			{
				line t = { i,j,g10[i][j] };
				line_arr[lap++] = t;
			}
	int n = 0; //0번 선택
	int mi, mw = INF;
	for (i = 0; i < lap; ++i)
		if (!line_arr[i].s) //s만 0인거 찾아도 됨. e는 0이 안됨
			if (mw > line_arr[i].w)
			{
				mw = line_arr[i].w;
				mi = i;
			} //가장 가중치 낮은 애 찾기
	printf("[0] to [%d] :   %d\n", line_arr[mi].e, line_arr[mi].w);
	int cnV = -1;
	int cV[MAX_VERTEX * MAX_VERTEX];
	cV[++cnV] = 0;
	cV[++cnV] = line_arr[mi].e;
	line_arr[mi].s = -1;	line_arr[mi].e = -1;	line_arr[mi].w = INF;
	tie(cV[0], cV[1]); //첫 번째 묶기
	while (cp < MAX_VERTEX - 1)
	{
		Queue q;
		initQ(&q);
		for (i = 0; i < lap; ++i)
			for (j = 0; j <= cnV; ++j)
				if (line_arr[i].s == cV[j] || line_arr[i].e == cV[j])
					pushQ(&q, line_arr[i]); //큐 썼음. ppt 119페이지에 3번 '이전에 선택한 정점' 단수로 써서 틀릴뻔 함. 정점들이 맞는 듯.
		line ml;	ml.w = INF;
		while (!is_emptyQ(&q))
		{
			line t = popQ(&q);
			bool p = false;
			for (i = 0; i <= cnV; ++i)
				if ((t.s == cV[i] && getPar(t.e) == getPar(cV[i])) || (t.e == cV[i] && getPar(t.s) == getPar(cV[i]))) //사이클 형성 간선 제외
				{
					p = true;
					break;
				}
			if (!p && t.w < ml.w)	ml = t;
		}
		for (i = 0; i < lap; ++i)
			if (line_arr[i].s == ml.s && line_arr[i].e == ml.e && line_arr[i].w == ml.w)
			{
				line_arr[i].s = -1;	line_arr[i].e = -1;	line_arr[i].w = INF;
				break;
			}
		printf("[%d] to [%d] :   %d\n", ml.s, ml.e, ml.w);
		tie(ml.s, ml.e); //부모 묶기
		bool p = true;
		for (i = 0; i <= cnV; ++i)
			if (cV[i] == ml.s)
			{
				cV[++cnV] = ml.e;
				p = false;
				break;
			}
		if (p)	cV[++cnV] = ml.s;
		cp++;
	}
	printf("\n");
}
void func4()
{
	int i, j, lap = 0;
	for (i = 0; i < MAX_VERTEX * MAX_VERTEX; ++i) //부모 찾기 초기화 (이번엔 간선 부모 찾기) //getPar : find, tie : union 함수임
		par[i] = i;
	line line_arr[1000];
	for (i = 0; i < MAX_VERTEX; ++i) //간선 제작
		for (j = i + 1; j < MAX_VERTEX; ++j)
			if (g10[i][j] != INF)
			{
				line t = { i,j,g10[i][j] };
				line_arr[lap++] = t;
			}
	int tree = MAX_VERTEX;
	int min[100];
	while (tree > 1)
	{
		memset(min, -1, sizeof min);
		Queue q;
		initQ(&q);
		for (i = 0; i < lap; ++i)
			pushQ(&q, line_arr[i]);
		for (i = 0; i < lap; ++i)
		{
			line t = popQ(&q);
			int x = getPar(t.s), y = getPar(t.e); //가중치 비교에 큐 씀
			if (x == y)	continue; //사이클 간선 째낌
			if (min[x] == -1 || line_arr[min[x]].w > line_arr[i].w)	min[x] = i;
			if (min[y] == -1 || line_arr[min[y]].w > line_arr[i].w)	min[y] = i;
		}
		for (j = 0; j < MAX_VERTEX; ++j)
		{
			if (min[j] == -1)	continue;
			int x = getPar(line_arr[min[j]].s), y = getPar(line_arr[min[j]].e);
			if (x == y)	continue;
			printf("# of Trees:  %d:\n        (%d   %d)[%d]\n", tree, line_arr[min[j]].s, line_arr[min[j]].e, line_arr[min[j]].w);
			tree--;
			tie(x, y);
		}
	}
	printf("# of Trees:  1:\n");
}

int main()
{
	printf("*** MST: Kruskal I Algorithm ***\n");
	func1();
	printf("*** MST: Kruskal II Algorithm ***\n");
	func2();
	printf("*** MST: Prim Algorithm ***\n");
	func3();
	printf("*** MST: Sollin Algorithm ***\n");
	func4();
	return 0;
}