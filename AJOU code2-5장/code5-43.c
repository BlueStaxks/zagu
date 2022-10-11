#include <stdio.h>
typedef struct {
	int data[100];
	int p;
} stack;
void init(stack* a)
{
	for (int i = 0; i < 100; ++i)
		a->data[i] = 0;
	a->p = -1;
}
short empty(stack* s)
{
	if (s->p == -1)
		return 1;
	return 0;
}
void push(stack* s, int k)
{
	if (s->p < 99)
		s->data[++(s->p)] = k;
}
int pop(stack* s)
{
	if (s->p == -1)
		return -1;
	int t = s->data[s->p];
	s->p--;
	return t;
}

int main()
{
	int a[100]; //원본
	int b[100]; //역순
	int i;
	for (i = 0; i < 100; ++i)
		a[i] = i + 1;

	stack s;
	init(&s);

	for (i = 0; i < 100; ++i)
		push(&s, a[i]);

	for (i = 0; i < 100; ++i)
		b[i] = pop(&s);

	for (i = 0; i < 100; ++i)
		printf("%d ", b[i]);

	return 0;
}