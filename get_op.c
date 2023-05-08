#include "monty.h"


char * get_op(char *str, instruction_t ops, unsigned int lineNum)
{
    int i = 0, j = 0;
    instruction_t operator = ops;
    char * command = "push"; 

            i = 0;
            j = 0;
            while(str[i])
            {

                while(str[i] == operator->opcode[j])
                {
                    j++;
                }
                i++;
                if (j == 3)
                {
                      ops->f();
                }
                
             }
}