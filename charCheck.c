#include "monty.h"

/**
 * charCheck - Function to check chars.
 *
 */

void charCheck(char *str, int lineNum)
{
	int i = 0;
	int isChar = 0;

	while(str[i])
	{
		if(isdigit(str[i]) != 0)
		{
			isChar = 1;
		}
		i++;
	}
	if (isChar == 1)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", lineNum);
		exit(EXIT_FAILURE);
	}
}
