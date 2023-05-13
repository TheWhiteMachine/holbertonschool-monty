#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* extern variables */
extern int data;

/* structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* instructions prototypes */
void push(stack_t **stack, unsigned int lineNum);
void pall(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void pop(stack_t **stack, unsigned int lineNum);
void swap(stack_t **stack, unsigned int lineNum);
void add(stack_t **stack, unsigned int lineNum);
void nop(stack_t **stack, unsigned int lineNum);

/* function prototypes */
int get_op(char *str, instruction_t ops[], unsigned int lineNum);
void charCheck(char *str, int lineNum);
void read_file(FILE *file_ptr, instruction_t *ops, stack_t **stack);

#endif