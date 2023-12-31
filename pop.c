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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(state.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	free(top);
}

/**
 * do_nothing - ...
 * @stack: ...
 * @line_number: ...
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
