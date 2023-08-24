#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
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
 * struct state_t - a state to track variables across modules
 * @file: file pointer to close the file from functions
 * @buffer: line returned from the file
 * @flag: a flag to toggle between stack and queue
 *
 * Description: a state like structure to access multile variables
 * from different functions
 */


typedef struct state_t
{
        stack_t **stack;
        FILE *file;
        char *buffer;
        int line_counter;
        int flag;
} state_t;

extern state_t *state; /*this makes sure state is in the global scope*/

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


void free_stack(stack_t **stack);
void push(stack_t **stack, char *number);
void print_all(stack_t **stack, char *number);
void print_top(stack_t **stack, char *number);
void pop(stack_t **stack, char *number);
void swap(stack_t **stack, char *number);
void add(stack_t **stack, char *number);
void do_nothing(stack_t **stack, char *number);
void function_caller(char *buffer);
char **tokenize(char *buffer);
void choose_f(char *opcode, char *n);

#endif
