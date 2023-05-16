#include "monty.h"

/**
 *  someErrorManage - some validations for functions
 * @stack: doble linked list
 * @lineNum: line number of reed instruction on monty file
 */

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
