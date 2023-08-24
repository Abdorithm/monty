#include "monty.h"

/**
 * push - ...
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL)
		return;
	if (state.arg[1] == NULL || not_a_number(state.arg[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(state.stack);
		free_args(state.arg);
		free(state.buffer);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	new->n = atoi(state.arg[1]);
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
	if (new->next != NULL)
		(new->next)->prev = new;
}

/**
 * pall - ...
 * @stack: ...
 * @line_number: ...
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * top - ...
 * @stack: ...
 * @line_number: ...
 */
void top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(state.stack);
		free_args(state.arg);
		free(state.buffer);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * not_a_number - ...
 * @s: ...
 * Return: 1 or 0
 */
int not_a_number(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (1);
	return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *copy;
	int i, size = 0;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;

	copy = (char *)malloc((sizeof(char) * size) + 1);
	if (copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(state.stack);
		free_args(state.arg);
		free(state.buffer);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
		copy[i] = str[i];
	copy[size] = '\0';

	return (copy);
}
