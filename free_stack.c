#include "monty.h"

/**
* free_stack - free the stack in case of an error
* @stack: pointer to the stack
*/

void free_stack(stack_t *stack)
{
	stack_t *nextNode;

	while (stack)
	{
		nextNode = stack->next;
		free(stack);
		stack = nextNode;
	}
}

/**
 * free_2d - frees an array of strings from
 * the heap.
 * @array: the array
 */
void free_args(char **array)
{
	int i = 0;
	
	while (array[i])
		free(array[i]), i++;
	free(array);
}
