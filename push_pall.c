#include "monty.h"


void push(stack_t **stack, unsigned int lineNum)
{
    puts("push function");
}
/**
 * main - main function
 * @argc: count of args
 * @argv: vector of args
 * Return: 0000000000000
*/
int main(int argc, char* argv[])
{
    char str[80];
    FILE* file_ptr;
    unsigned int lineNum = 0;
    stack_t ** my_stack;
    instruction_t ops[] = {
	{"push", push},
	{NULL, NULL},
    };


    if (argc < 1)
        fprintf(stderr, "USAGE: monty file");

    file_ptr = fopen("./bytecodes/00.m", "r");

          // Failed Condition
    if (file_ptr == NULL) {
        fprintf(stderr, "Error: Can't open file <%s>", argv[0]);
        exit (1);
    }
     while(fgets(str, 80, file_ptr) != NULL)
        {
            get_op(str, ops, lineNum);
            lineNum++;
        }


    fclose(file_ptr);

    return (0);

}