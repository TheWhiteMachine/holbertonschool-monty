#include "monty.h"
int data = 0;

/**
 * main - main function
 * @argc: count of args
 * @argv: vector of args
 * Return: 0 or 1 on error.
 */

int main(int argc, char *argv[])
{
	char str[80];
	FILE *file_ptr;
	unsigned int lineNum = 1;
	stack_t **my_stack;
	int opIndex = 0;
	char *opcode, *token;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	my_stack = malloc(sizeof(stack_t));
	if (!my_stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	*my_stack = NULL;
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(str, 80, file_ptr) != NULL)
	{
		data = 0;
		if (str != NULL)
		{
			token = strtok(str, " \t\n");
			if (token == NULL || strcmp(token, "\n") == 0)
			{
				lineNum++;
				continue;
			}
			opcode = token;
			opIndex = get_op(opcode, ops, lineNum);
			token = strtok(NULL, " \t\n");
			if (token != NULL)
			{
				if (strcmp(token, "0") == 0 || strcmp(token, "-0") == 0)
					data = 0;
				else
				{
					data = atoi(token);
					if (data == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", lineNum);
						exit(EXIT_FAILURE);
					}
				}
			}
			else if (strcmp(opcode, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNum);
				exit(EXIT_FAILURE);
			}
		}
		lineNum++;
		if (opcode != NULL || opIndex != '\0')
			ops[opIndex].f(my_stack, lineNum);
	}
	fclose(file_ptr);
	free(*my_stack);

	return (0);
}
