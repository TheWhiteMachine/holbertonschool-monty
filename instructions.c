#include "monty.h"

/**
 * pall - print all the list
 * @stack: a linked list to print
 * @lineNum: line number of instrucci
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	(void)lineNum;
	stack_t *myStack;

	myStack = *stack;
	while (myStack)
	{
		printf("%d\n", myStack->n);
		myStack = myStack->next;
	}
}

/**
 * push - add an elment on top of a linked list
 * @stack: a linked list to print
 * @lineNum: line number of instructions.
 */

void push(stack_t **stack, unsigned int lineNum)
{
    extern int data;

	stack_t *myStack = NULL;

	(void)lineNum;
	myStack = malloc(sizeof(stack_t));
	if (!myStack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(myStack);
		exit(EXIT_FAILURE);
	}
	if (!*stack)
	{
		myStack->n = data;
		myStack->prev = NULL;
		myStack->next = NULL;
		*stack = myStack;
	}
	else
	{
		myStack->n = data;
		myStack->prev = NULL;
		myStack->next = *stack;
		(*stack)->prev = myStack;
		*stack = myStack;
	}
}