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

	while (fgets(str, 80, file_ptr) != NULL)
	{
		data = 0;
		if (str == NULL || strcmp(str, "\n") == 0)
		{
			lineNum++;
			continue;
		}
		opcode = strtok(str, " \t\n");
		if (opcode == NULL)
		{
			lineNum++;
			continue;
		}
		opIndex = get_op(opcode, ops, lineNum);
		token = strtok(NULL, " \t\n");
		if (token != NULL)
		{
			data = atoi(token);
			if (strcmp(token, "0") == 0 && token[0] != '-')
				data = 0;
			//if (data == 0 && strcmp(opcode, "push") == 0)
			//{
			//	fprintf(stderr, "L%d: usage: push integer\n", lineNum);
			//	exit(EXIT_FAILURE);
			//}
		}
		else if (strcmp(opcode, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNum);
			exit(EXIT_FAILURE);
		}
		lineNum++;
		if (opcode != NULL && opIndex != -1)
			ops[opIndex].f(stack, lineNum);
	}
}
