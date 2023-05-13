#include "monty.h"
/**
 * get_op - function to get instructions.
 *  @str: a string.
 *  @ops: a instruction.
 *  @lineNum: number of line.
 *
 *  Return: an int to the instruction.
*/
int get_op(char *str, instruction_t ops[], unsigned int lineNum)
{
	int i = 0;

	while(ops[i].opcode)
	{
		if (strcmp(str, ops[i].opcode) == 0)
		{
			return(i);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, str);
	exit(EXIT_FAILURE);
}
