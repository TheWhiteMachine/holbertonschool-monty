#include "monty.h"

char *get_op(char *str, instruction_t ops[], stack_t **myStack, unsigned int lineNum)
{
    int i = 0;
    char *token;
    char *delim = " \n\0";
    char *opcode;
    stack_t *stack = malloc(sizeof(stack_t));
    stack_t *findLast;
    int data = 0;

    token = strtok(str, delim);

    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, token) == 0)
        {
            while (token != NULL)
            {
                printf("data %s", token);
                token = strtok(NULL, delim);
                if (token != NULL)
                {
                    data = atoi(token);
                    stack->n = data;
                    stack->next = NULL;
                    if (*myStack == NULL)
                    {
                        *myStack = stack;
                    }
                    else
                    {
                        findLast = *myStack;
                        while (findLast != NULL)
                        {
                            if (findLast->next == NULL)
                            {
                                findLast->next = stack;
                                break;
                            }
                            findLast = findLast->next;
                        }
                    }
                }
            }
            ops[i].f(myStack, lineNum);
        }
    }
}

