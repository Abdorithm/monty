#include "monty.h"

/**
 * divide - devide the top two elements
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/
void divide(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	result = top->next->n / top->n;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
