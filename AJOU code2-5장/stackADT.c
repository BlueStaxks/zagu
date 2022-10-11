/*******************************************************/
/****  Stack ADT as in a C Structure - by JHY    ****/
/*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char itemType;
typedef struct STACK stackType;
typedef stackType* stackPoint;
typedef struct STACK {
	int top;						// stack top (index)
	itemType item[STACK_SIZE];		// stack items
	int (*isEmpty)(struct STACK* s); // check if stack empty
	int (*isFull)(stackType* s);		// check if stack full
	void (*push)(stackPoint s, itemType x);	// push
	itemType(*pop)(stackPoint s);			// pop
	itemType(*peek)(stackPoint s);			// peek
} StackADT;

int isEmpty(stackPoint s) {
	if (s->top < 0) return 1;
	else return 0;
}

int isFull(stackPoint s) {
	if (s->top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(stackPoint s, itemType x) {
	if (isFull(s)) return;
	else 	s->item[++s->top] = x;
}

itemType pop(stackPoint s) {
	if (isEmpty(s)) return -1;
	else return s->item[s->top--];
}

itemType peek(stackPoint s) {
	if (isEmpty(s)) return -1;
	else return (s->item[s->top]);
}

void printStack(stackPoint s) {
	printf("[Top = %2d]", s->top);
	for (int i = 0; i <= s->top; i++) 	printf("\t%c", s->item[i]);
	printf("\n");
}


int main() {
	stackType stack = // create & initialize a stack
	{ -1, {0}, isEmpty, isFull, push, pop, peek };
	stackType* s = &stack; // pointer to the stack for use in parameter passing

	printf("\n** Stack ADT **\n");
	printStack(s);
	s->push(s, 'A'); printf("push => %c ", 'A');
	printStack(s);		// 1 ª¿‘
	s->push(s, 'B'); printf("push => %c ", 'B');
	printStack(s);		// 2 ª¿‘
	s->push(s, 'C'); printf("push => %c ", 'C');
	printStack(s);		// 3 ª¿‘

	printf("peek => %c\n", s->peek(s));

	printf("pop  => %c ", s->pop(s)); // ªË¡¶
	printStack(s);
	printf("pop  => %c ", s->pop(s)); // ªË¡¶
	printStack(s);
	printf("pop  => %c ", s->pop(s)); // ªË¡¶
	printStack(s);
	return 0;
}