#include "monty.h"

void push(stack_t **stack, unsigned int lineNum)
{
    stack_t *myStack = NULL;
    int num = lineNum;

    myStack = malloc(sizeof(stack_t));
    if (!myStack)
    {
        fprintf(stderr, "%s", "Error: malloc failed\n");
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

void pall(stack_t **stack, unsigned int lineNum)
{
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
 * Return: 0000000000000
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
    // instrucions structure
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};
    my_stack = malloc(sizeof(stack_t));
    if (!my_stack)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    *my_stack = NULL;

    if (argc != 2)
        fprintf(stderr, "USAGE: monty file\n");

    file_ptr = fopen(argv[1], "r");

    if (file_ptr == NULL)
    {
        fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
        exit(1);
    }

    while (fgets(str, 80, file_ptr) != NULL)
    {
        token = strtok(str, " \t");
        opcode = strdup(token);
        opIndex = get_op(opcode, ops, lineNum);
        token = strtok(NULL, " \t");
        if (token != NULL)
        {
            data = atoi(token);
            if (isdigit(data) == 0)
            {
                fprintf(stderr, "L<%d>: usage: push integer\n", lineNum);
                exit(EXIT_FAILURE);
            }
        }

        lineNum++;
        ops[opIndex].f(my_stack, lineNum);
    }

    fclose(file_ptr);

    return (0);
}