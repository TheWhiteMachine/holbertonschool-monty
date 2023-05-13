#include "monty.h"

/**
 * pall - add an elment on top of a linked list
 * @stack: a linked list to print
 * @lineNum: line number of instrucci
 */

void push(stack_t **stack, unsigned int lineNum)
{
	stack_t *myStack = NULL;
	(void)lineNum;

	myStack = malloc(sizeof(stack_t));

	if (!myStack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!*stack)
	{
		myStack->n = data;
		myStack->prev = NULL;
		myStack->next = NULL;
		*stack = myStack;
	}
	else
	{
		myStack->n = data;
		myStack->prev = NULL;
		myStack->next = *stack;
		(*stack)->prev = myStack;
		*stack = myStack;
	}
}

/**
 * pall - print all the list
 * @stack: a linked list to print
 * @lineNum: line number of instrucci
 */

void pall(stack_t **stack, unsigned int lineNum)
{
	(void)lineNum;
	stack_t *myStack;

	myStack = malloc(sizeof(stack_t));
	myStack = *stack;
	while (myStack)
	{
		printf("%d\n", myStack->n);
		myStack = myStack->next;
	}
}

/**
 * main - main function
 * @argc: count of args
 * @argv: vector of args
 * Return: 0 or exit messages
 */
int main(int argc, char *argv[])
{
	char str[80];
	FILE *file_ptr;
	unsigned int lineNum = 1;
	stack_t **my_stack;
	int opIndex = 0;
	char *opcode, *token;
	extern int data;
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
	free(my_stack);
	return (0);
}
