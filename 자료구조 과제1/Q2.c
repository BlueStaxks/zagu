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
        s->top = s->top->link; //지움
        free(temp); // 해제
        return data;
    }
    exit(1);
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
        free(temp);
        return data;
    }
    exit(1);
}//---------------------------------------------------여기까지 스택과 큐 정의
int N, c;
int dep[10];
bool visited[10];
bool possible(int* num) //교제 참고
{
    Queue rq; //LQ는 딱히 필요가 없음
    initQ(&rq);
    Stack s;
    initS(&s);
    int i;
    for (i = 0; i < N; ++i)
        pushQ(&rq, i + 1);
    i = 0;
    while (!is_emptyQ(&rq) || !is_emptyS(&s))
    {
        if (!is_emptyQ(&rq) && rq.front->data == num[i])
        {
            popQ(&rq);
            i++;
        }
        else if (!is_emptyQ(&rq) && rq.front->data < num[i])
            while (!is_emptyQ(&rq) && rq.front->data < num[i])
                push(&s, popQ(&rq));
        else
        {
            if (is_emptyS(&s))
                return false;
            else if (s.top->data == num[i])
            {
                pop(&s);
                i++;
            }
            else
                return false;
        }
    }
    if (is_emptyS(&s))
        return true;
    else
        return false;
}
void check(int x)
{
    if (x == N && possible(dep)) //dep[]에 만들어진 수열 있음 //모든 수열 다 만들고 가능한 수열만 뽑아 쓰는 것
    {
        printf("\t%d:\t", c++);
        for (int i = 0; i < N; ++i)  printf("%d", dep[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++)
        if (!visited[i + 1])
        {
            dep[x] = i + 1;
            visited[i + 1] = true;
            check(x + 1);
            visited[i + 1] = false;
        }
}
int main()
{
    while (1)
    {
        int i;
        printf("*** 숫자 수 (5 이하 자연수), N = ");
        scanf("%d", &N);
        if (N > 5)
        {
            printf("+++ 5 이하 자연수를 입력하세요!\n");
            continue;
        }
        else if (!N)
        {
            printf("Bye!!!\n");
            return 0;
        }
        for (i = 0; i < 10; ++i) visited[i] = false;
        c = 1;
        check(0);
    }
}