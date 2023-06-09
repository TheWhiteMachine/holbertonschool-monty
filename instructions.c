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

	if (!stack)
	{
		free_stack(stack);
		free(stack);
	}
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
			free(myStack);
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

/**
 * pop - delete last element on stack
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */

void pop(stack_t **stack, unsigned int lineNum)
{
	stack_t *myStack = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (*stack)
		{
			if ((*stack)->next)
			{
				myStack = *stack;
				(*stack) = (*stack)->next;
				(*stack)->prev = NULL;
				if (!(myStack))
				{
					free_stack(stack);
					free(*stack);
					*stack = NULL;
				}
				free(myStack);
			}
			else
			{
				free(myStack);
				free(*stack);
				myStack = NULL;
				*stack = NULL;
			}
		}
	}
}

/**
 * swap - swap last element and its previous
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */

void swap(stack_t **stack, unsigned int lineNum)
{
	stack_t *swapNode = NULL;
	unsigned int swpToNode = 0;

	(void)lineNum;

	if (*stack && (*stack)->next)
	{
		swapNode = (*stack)->next;
		swpToNode = (*stack)->n;
		(*stack)->n = swapNode->n;
		swapNode->n = swpToNode;
	}
	else
	{
		if (!stack)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum - 1);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum - 1);
			exit(EXIT_FAILURE);
		}
	}
}
