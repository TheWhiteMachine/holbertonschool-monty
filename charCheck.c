#include "monty.h"

/**
 * charCheck - Function to check chars.
 * @str: pointer to string.
 * @lineNum: number of line integer.
 */
void charCheck(char *str, char *opcode, int lineNum)
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
			exit(0);
		fprintf(stderr, "L%d: usage: push integer\n", lineNum);
		exit(EXIT_FAILURE);
	}
}
