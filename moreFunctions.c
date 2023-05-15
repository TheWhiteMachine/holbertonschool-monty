#include "monty.h"

/**
 * _add - sum last element and its previous and erase one elment
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */

void add(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp = NULL;

	(void)lineNum;
	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->n = temp->n + (*stack)->n;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum - 1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - do nothing at all
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */
void nop(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
}
