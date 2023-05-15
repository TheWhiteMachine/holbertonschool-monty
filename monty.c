#include "monty.h"

/**
 * main - main function
 * @argc: count of args
 * @argv: vector of args
 *
 * Return: 0 or 1 on error.
 */

int main(int argc, char *argv[])
{
	FILE *file_ptr;
	stack_t **stack;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		/**
		 *		{"add", add},
		 *		{"nop", nop},
		 */
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t *));
	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	*stack = NULL;
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(file_ptr, ops, stack);
	fclose(file_ptr);
	free_stack(stack);
	free(stack);
	return (0);
}
