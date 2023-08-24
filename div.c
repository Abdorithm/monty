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
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
                exit(EXIT_FAILURE);
	}
	result = top->n / top->next->n;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
