#include "monty.h"

void setList(stack_t **stack)
{
	stack_t **my_stack;

	my_stack = malloc(sizeof(stack_t));

	if (!my_stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	*my_stack = NULL;
}