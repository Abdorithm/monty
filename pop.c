#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		fclose(state->file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	free(top);
}
