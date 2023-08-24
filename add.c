#include "monty.h"

/**
 * add - add the top two elements
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int length = 0, result = 0;

	top = *stack;
	while (top)
	{
		top = top->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(state.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	result = top->n + top->next->n;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
