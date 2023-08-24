#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @number: the integer parameter
 * Return: void
*/

void pop(stack_t **stack, char *number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", state->line_counter);
		fclose(state->file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	free(top);
}
