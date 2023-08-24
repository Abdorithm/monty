#include "monty.h"

/**
 * push - ...
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	if (state.arg == NULL || not_a_number(state.arg))
		fprintf(stderr, "%d: usage: push integer", line_number), exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t *));
	if (new == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	new->n = atoi(state.arg);
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

/**
 * pall - ...
 * @stack: ...
 * @line_number: ...
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
		printf("%d\n", tmp->n), tmp = tmp->prev;
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

	while (tmp->next != NULL)
		tmp = tmp->next;
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
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	for (i = 0; i < size; i++)
		copy[i] = str[i];
	copy[size] = '\0';

	return (copy);
}
