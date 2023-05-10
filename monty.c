#include "monty.h"

void push(stack_t **stack, unsigned int lineNum)
{
    puts("push starting");
    // stack_t *myStack = NULL;
    // int num = lineNum;

    // {
    //     stack_t *myStack = NULL;
    //     int num = lineNum;

    //     myStack = malloc(sizeof(stack_t));
    //     if (!myStack)
    //     {
    //         fprintf(stderr, "%s", "Error: malloc failed\n");
    //         exit(EXIT_FAILURE);
    //     }

    //     if (!*stack)
    //     {
    //         myStack->n = num;
    //         myStack->prev = NULL;
    //         myStack->next = NULL;
    //         *stack = myStack;
    //     }
    //     else
    //     {
    //         myStack->n = num;
    //         myStack->prev = NULL;
    //         myStack->next = *stack;
    //         (*stack)->prev = myStack;
    //         *stack = myStack;
    //     }
    // }
    // myStack = malloc(sizeof(stack_t));
    // if (!myStack)
    // {
    //     fprintf(stderr, "%s", "Error: malloc failed\n");
    //     exit(EXIT_FAILURE);
    // }

    // if (!*stack)
    // {
    //     myStack->n = num;
    //     myStack->prev = NULL;
    //     myStack->next = NULL;
    //     *stack = myStack;
    // }
    // else
    // {
    //     myStack->n = num;
    //     myStack->prev = NULL;
    //     myStack->next = *stack;
    //     (*stack)->prev = myStack;
    //     *stack = myStack;
    // }
}

void pall(stack_t **stack, unsigned int lineNum)
{

    puts("pall starting");
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
    stack_t **my_stack = malloc(sizeof(stack_t));
    int opIndex = 0;
    char *opcode;
    char *token;
    int data;
    // instrucions structure
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    *my_stack = NULL;

    // if (argc != 2)
    //     fprintf(stderr, "USAGE: monty file");

    file_ptr = fopen("./bytecodes/00.m", "r");

    // if (file_ptr == NULL) {
    //     fprintf(stderr, "Error: Can't open file <%s>", argv[0]);
    //     exit (1);
    // }

    while (fgets(str, 80, file_ptr) != NULL)
    {
        token = strtok(str, " \t");
        opcode = strdup(token);
        opIndex = get_op(opcode, ops);
        token = strtok(NULL, " \t");
        if (token != NULL)
        {
            data = atoi(token);
            printf("data en token: %d", data);
        }

        ops[opIndex].f(my_stack, lineNum);
        lineNum++;
    }

    fclose(file_ptr);

    return (0);
}