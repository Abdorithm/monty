#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


#define INIT_STATE {NULL, NULL, NULL, NULL, 0}



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
 * struct state_s - a state to track variables across modules
 * @file: file pointer to close the file from functions
 * @line_counter: number of lines ina file
 * @stack: the stack
 * @arg: arg from line
 *
 * Description: a state like structure to access multile variables
 * from different functions
 */


typedef struct state_s
{
	stack_t *stack;
	FILE *file;
	char *buffer;
	char **arg;
	int line_counter;
} state_t;

extern state_t state;

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

int not_a_number(char *s);
int checkEmpty(char *buffer);
void free_stack(stack_t *stack);
char *_strdup(char *str);
void free_args(char **array);

/* operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);



void function_caller(char *buffer);
char **tokenize(char *buffer);
void choose_f(char *opcode);

#endif
