#include "monty.h"

int get_op(char *str, instruction_t ops[], unsigned int lineNum)
{
    int i = 0;

    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, str) == 0)
        {
            return (i);
        }
    }
    printf("L<%d>: unknown instruction <%s>", lineNum, str);
    exit(EXIT_FAILURE);
}
