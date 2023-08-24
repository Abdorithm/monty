#include "monty.h"

/**
 * mod - calculate the rest of the div of top two elements
 * @stack: pointer to the stack
 * @line_number: ...
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	if (top->n == 0)
	{	
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = top->next->n % top->n;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
