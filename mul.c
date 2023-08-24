#include "monty.h"

/**
 * mul - multiply the top two elements
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	result = top->n * top->next->n;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
