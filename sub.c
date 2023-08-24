#include "monty.h"

/**
 * sub - sub the top two elements
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result =(*stack)->n - (*stack)->next->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;
}
