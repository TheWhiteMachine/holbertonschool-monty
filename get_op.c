#include "monty.h"

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
