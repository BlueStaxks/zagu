#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node* link;
}Node;
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
}
void radixSort(int a[], int size)
{
	int k, i;
    for (k = 10; k <= 1000; k *= 10)
	{
        Queue q[10];
        for (i = 0; i < 10; ++i)    initQ(&q[i]);
        for (i = 0; i < size; ++i)
            pushQ(&q[(a[i] % k)/(k/10)], a[i]);
        int p = -1;
        for (i = 0; i < 10; ++i)
        {
            while (!is_emptyQ(&q[i]))
                a[++p] = popQ(&q[i]);
        }
        for (i = 0; i < 7; ++i)
            printf("%d ", a[i]);
        printf("\n\n");
	}
}
int main()
{
	int a[] = { 379,508,706,193,984,155,133 };
    radixSort(a, 7);
    return 0;
}
/*

    2단계 후 706 508 133 155 379 984 193 가 되는 것을 알 수 있다.

    4번이 답.

*/