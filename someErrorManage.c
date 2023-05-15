#include "monty.h"

void someErrorManage(char *token, char *opcode, int lineNum, stack_t **stack)
{

	if (token != NULL)
	{
		charCheck(token, opcode, lineNum, stack);
		data = atoi(token);
		if (strcmp(token, "0") == 0 && token[0] != '-')
			data = 0;
	}
	else if (strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNum);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "pop") == 0 && lineNum == 1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		exit(EXIT_FAILURE);
	}
}

/**
 * _add - sum last element and its previous and erase one elment
 * @stack: pointer to top of stack
 * @lineNum: line number of instruction.
 */

void _add(stack_t **stack, unsigned int lineNum)
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
		fprintf(stderr, "L%d: can't sum, stack too short\n", lineNum - 1);
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
