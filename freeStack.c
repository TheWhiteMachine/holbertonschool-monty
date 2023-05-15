#include "monty.h"

/**
 * free_stack - Frees a stack_t stack and all its nodes.
 * @stack: A pointer to the top element of the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current, *next;

    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
