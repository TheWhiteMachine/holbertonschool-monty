#include "monty.h"

/**
 * charCheck - Function to check chars.
 * @str: pointer to string.
 * @opcode: string with operator
 * @lineNum: number of line integer.
 * @stack: linked list with data.
 */
void charCheck(char *str, char *opcode, int lineNum, stack_t **stack)
{
	int i = 0;
	int isChar = 0;

	while (str[i])
	{
		if (isdigit(str[i]) == 0 && str[i] != '-')
		{
			isChar = 1;
		}
		i++;
	}
	if (isChar == 1)
	{
		if (strcmp(opcode, "pop") == 0)
		{
			free_stack(stack);
			exit(0);
		}
		fprintf(stderr, "L%d: usage: push integer\n", lineNum);
		free_stack(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}
}
