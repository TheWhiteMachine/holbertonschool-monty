#include "monty.h"
int data = 0;

/**
 * read_file - function to handle files.
 * @file_ptr: pointer to the file to be read
 * @ops: array of operation codes and functions
 * @stack: pointer to top of the stack
 */

void read_file(FILE *file_ptr, instruction_t *ops, stack_t **stack)
{
	char str[80], *opcode, *token;
	unsigned int lineNum = 1;
	int opIndex = 0;
	int directExecution;

	while (fgets(str, 80, file_ptr) != NULL)
	{
		data = 0;
		directExecution = 0;
		opcode = strtok(str, " \t\n");
		if (str == NULL || strcmp(str, "\n") == 0 || opcode == NULL)
		{
			lineNum++;
			continue;
		}
		opIndex = get_op(opcode, ops, lineNum);
		token = strtok(NULL, " \t\n");
		if (opIndex > 0 && opIndex < 7)
			directExecution = 1;
		switch (directExecution)
		{
		case 1:
			lineNum++;
			ops[opIndex].f(stack, lineNum);
			continue;
		}
		someErrorManage(token, opcode, lineNum, stack);
		lineNum++;
		if (opcode != NULL && opIndex != -1)
			ops[opIndex].f(stack, lineNum);
	}
}
