#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node* link;
}Node;
typedef struct {
    Node* top;
}Stack;
void initS(Stack* s)
{
    s->top = NULL;
}
bool is_emptyS(Stack* s)
{
    return (s->top == NULL);
}
void push(Stack* s, int item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}
int pop(Stack* s)
{
    if (!is_emptyS(s))
    {
        Node* temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
    exit(1);
}
void print_stack(Stack* s)
{
    for (Node* p = s->top; p != NULL; p = p->link)
        printf("%d-> ", p->data);
    printf("NULL \n");
}
//--------------------------
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
void pushQ(Queue* q, int data)
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
}
int popQ(Queue* q)
{
    if (!is_emptyQ(q))
    {
        Node* temp = q->front;
        int data = temp->data;
        q->front = temp->link;
        if (q->front == NULL) // 공백상태
            q->rear = NULL;
        free(temp); // 해제
        return data;
    }
    exit(1);
}
void print_queue(Queue* q)
{
    Node* p;
    for (p = q->front; p != NULL; p = p->link)
        printf("%c", p->data);
} //---------------------------------------------------여기까지 일반 스택과 큐 정의
typedef struct Tdata {
    int data;
    int index;
    struct Tdata* left;
    struct Tdata* right;
}Tdata; //이진트리 노드를 스택과 큐에 넣어야 하기 때문에 구조체 생성
typedef struct TNode {
    Tdata* data; //포인터로 만들어야 트리를 만들 때 left, right를 설정하기 편함
    struct TNode* link;
}TNode;
typedef struct {
    TNode* top;
}TStack;
void initST(TStack* s)
{
    s->top = NULL;
}
bool is_emptyST(TStack* s)
{
    return (s->top == NULL);
}
void pushT(TStack* s, Tdata* item)
{
    TNode* temp = (TNode*)malloc(sizeof(TNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}
Tdata* popT(TStack* s)
{
    if (!is_emptyST(s))
    {
        TNode* temp = s->top;
        Tdata* k = s->top->data;
        s->top = s->top->link; //지움
        free(temp);
        return k;
    }
    exit(1);
}
//--------------------------------------
typedef struct {
    TNode* front, * rear;
}TQueue;
void initQT(TQueue* q)
{
    q->front = q->rear = NULL;
}
bool is_emptyQT(TQueue* q)
{
    return (q->front == NULL);
}
void pushQT(TQueue* q, Tdata* data)
{
    TNode* temp = (TNode*)malloc(sizeof(TNode));
    temp->data = data;
    temp->link = NULL; // 큐의 마지막에 들어가므로 새로운 노드의 링크부분은 NULL
    if (is_emptyQT(q))
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
    }
}
Tdata* popQT(TQueue* q)
{
    if (!is_emptyQT(q))
    {
        TNode* temp = q->front;
        Tdata* k = temp->data;
        q->front = temp->link;
        if (q->front == NULL) // 공백상태
            q->rear = NULL;
        free(temp);
        return k;
    }
    exit(1);
}
//-------------------------------------여기까진 구조체 스택과 큐 정의
int us(char a) //우선순위 자료집
{
    if (a == '(' || a == ')')   return 100;
    else if (a == '*' || a == '/' || a == '%' || a == '^')  return 10;
    else if (a == '+' || a == '-')  return 5;
    else if (a == '=')  return 1;
    return 0;
}
void huwi(char a[])
{
    int i, p = -1;
    char s[10000] = { "" };
    Queue q;
    Queue LQ;
    initQ(&q); //후위 계산용
    initQ(&LQ); //트리 제작용 (둘 다 똑같이 후위연산식이 들어감)
    for (i = 0; a[i] != '\0'; ++i)
    {
        if (('0' <= a[i] && a[i] <= '9') || ('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //숫자, 알파벳
        {
            pushQ(&q, a[i]);
            pushQ(&LQ, a[i]);
        }
        else if (p == -1)
            s[++p] = a[i]; //스택 비었으면 그냥 추가
        else if (a[i] == ')')
        {
            while (s[p] != '(')
            {
                pushQ(&q, s[p]);
                pushQ(&LQ, s[p]);
                p--;
            }
            p--;
        }
        else if (s[p] == '(' || us(s[p]) < us(a[i])) //s[p] < a[i] (우선순위)   수가 클 수록 높음
            s[++p] = a[i]; //스택 추가
        else if (us(s[p]) >= us(a[i]))
        {
            while (s[p] != '(' && us(s[p]) >= us(a[i]) && p >= 0)
            {
                pushQ(&q, s[p]);
                pushQ(&LQ, s[p]);
                p--;
            }
            s[++p] = a[i]; //스택 추가
        }
    }
    while (p >= 0) //남은거 다 넣기
    {
        pushQ(&q, s[p]);
        pushQ(&LQ, s[p]);
        p--;
    }
    TStack LS;     //트리 제작 시작
    initST(&LS);
    while (!is_emptyQ(&LQ))
    {
        Tdata* tdp = (Tdata*)malloc(sizeof(Tdata)); //동적 할당 하면 free하기 전 까진 안사라짐. 이진트리는 Tdata로만 쌓일 예정이므로 필요함.
        Tdata td;                                                                        //또한 Tdata는 일단 만들어 지면 반드시 쓰이므로 free할 일도 없음
        int t = popQ(&LQ); //후위연산식 앞에서 하나씩 가져오기
        td.data = t;    td.left = NULL;    td.right = NULL; //NULL로 해놔야 끝인지 알 수 있음
        if (!(48 <= t && t <= 57)) //연산자
        {
            Tdata* right = popT(&LS); //연산할 것 2개 뽑아서 연산자 노드 좌우에 배치. 뽑은 2개는 숫자일 수도 있고 계산 결과가 될 작은 이중트리일 수도 있음
            Tdata* left = popT(&LS);
            td.left = left;
            td.right = right;  //피연산자 그룹 2개 나온걸 연산하게 하고 그걸 스택에 넣는 것
        }
        *tdp = td; //보존시키기
        pushT(&LS, tdp); //숫자든 연산자든 스택에 넣어야 함. 숫자면 그냥 들어가는거고 연산자여도 그 연산자 노드를 숫자처럼 취급하기 때문
    } //다시 돌게 되면 td는 사라지지만 tdp는 사라지지 않음
    Tdata* root = popT(&LS); //여기까지 후위 연산식으로 제작한 트리 완성됨 //root는 가장 첫 노드(가장 위)가 됨
    root->index = 1;  //여기부턴 트리에 인덱스 설정
    TQueue TQ;
    initQT(&TQ);
    pushQT(&TQ, root);
    int c = 0;
    while (!is_emptyQT(&TQ))
    {
        TNode* po = TQ.front;
        int s = 0;
        while (po != NULL)
        {
            s++;
            po = po->link;
        } //큐의 크기 측정 (s)
        printf("\n  \tLeval[");
        if (c < 10)    printf(" ");
        printf("%d]:  ", c);
        while (s--) //레벨 체크용
        {
            Tdata* data = popQT(&TQ);
            printf("\t%c[", data->data);
            if (data->index < 10)  printf(" ");
            printf("%d]", data->index);
            Tdata* dataL = data->left;
            Tdata* dataR = data->right;
            if (dataL != NULL) //NULL이면 끝인거니까 필요 없음
            {
                dataL->index = data->index * 2;
                pushQT(&TQ, dataL);
            }
            if (dataR != NULL)
            {
                dataR->index = data->index * 2 + 1; //인덱스 입력
                pushQT(&TQ, dataR);
            }
        }
        c++;
    }
    printf("\n  ** Postorder Traversal:\t");
    print_queue(&q); //후위연산식 전체 출력
    printf("\t(=> ");
    Stack st;
    initS(&st);
    while (!is_emptyQ(&q)) //후위연산식 계산
    {
        int t = popQ(&q);
        if (48 <= t && t <= 57)
            push(&st, t - 48); //char을 int로 변환(0은 char로 48이니까 빼줌)
        else
        {
            int t2 = pop(&st);
            int t1 = pop(&st);
            switch (t) {
            case 37: push(&st, t1 % t2);    break;
            case 42: push(&st, t1 * t2);    break;
            case 43: push(&st, t1 + t2);    break;
            case 45: push(&st, t1 - t2);    break;
            case 47: push(&st, t1 / t2);    break;
            }
        }
    }
    printf("%d)\n\n", pop(&st));
}
int main()
{
    printf("************ Tree For Expression **************\n");
    while (1)
    {
        printf("* Input Infix String: "); //   1 + (2 - 3 * 4 / (5 + 6)) - 7
        char a[1000];
        char t;
        int i = 0;
        while ((t = getchar()) != '\n')
            if (t != ' ')
                a[i++] = t;  //공백 없이 입력
        a[i] = '\0';
        printf("  +++ Build Tree +++\n  ** Level-order Traversal :");
        huwi(a);
    }
}