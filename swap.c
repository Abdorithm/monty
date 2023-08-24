#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @number: the integer parameter
 * Return: void
*/
void swap(stack_t **stack, char *number)
{
	stack_t *temp;
	int length = 0, tempn;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", state->line_counter);
		fclose(state->file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	tempn = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tempn;
}
