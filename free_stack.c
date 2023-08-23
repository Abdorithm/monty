#include "monty.h"

/**
* free_stack - free the stack in case of an error
* @stack: pointer to the stack
*/

void free_stack(stack_t *stack)
{
	stack_t *nextNode = stack;

	while (stack)
	{
		nextNode = stack->next;
		free(stack);
		stack = nextNode;
	}
}
