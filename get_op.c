#include "monty.h"

char *get_op(char *str, instruction_t ops[], stack_t **myStack, unsigned int lineNum)
{
    int i = 0;
    char *token;
    char *delim = " \n\0";
    char *opcode;
    stack_t *stack = malloc(sizeof(stack_t));
    stack_t *findLast =malloc(sizeof(stack_t));
    int data = 0;

    token = strtok(str, delim);
 

    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, token) == 0)
        {
            while (token != NULL)
            {
                token = strtok(NULL, delim);
                data = atoi(token);
                printf("data que pasó por atoi : %d \n", data);
      
                if (token != NULL)
                {
                    stack->n = data;
 
                    if (*myStack == NULL)
                    {

                        *myStack = stack;
                        printf("data copiado en  pila : %d ", stack->n);
                        break;
                    }
                    else
                    {
                        findLast = *myStack;
                        while (findLast != NULL)
                        {
                            if (findLast->next == NULL )
                            {
                                findLast->next = stack;
                                printf("data en segunda cola %d\n",findLast->n);
                                puts("segunda vez");
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

