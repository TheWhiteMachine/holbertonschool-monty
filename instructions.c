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
	stack_t *myStack = NULL;

	(void)lineNum;
	myStack = malloc(sizeof(stack_t));
	if (!myStack)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
		if (*stack == NULL)
		{
			free_stack(stack);
			free(stack);
		}
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum - 1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/*
 *void pop(stack_t **stack, unsigned int lineNum);
 *void swap(stack_t **stack, unsigned int lineNum);
 *void add(stack_t **stack, unsigned int lineNum);
 *void nop(stack_t **stack, unsigned int lineNum);
 */
