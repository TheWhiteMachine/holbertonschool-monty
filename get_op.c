#include "monty.h"

int get_op(char *str, instruction_t ops[])
{
    int i = 0;

    for (i = 0; ops[i].opcode; i++)
    {
        if (strcmp(ops[i].opcode, str) == 0)
        {
            return (i);
        }
    }

    exit(1);
}
