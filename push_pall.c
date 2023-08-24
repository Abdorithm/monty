#include "monty.h"

/**
 * push - ...
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{

}

/**
 * pall - ...
 * @stack: ...
 * @line_number: ...
 */
void pall(stack_t **stack, unsigned int line_number)
{

}

/**
 * top - ...
 * @stack: ...
 * @line_number: ...
 */
void top(stack_t **stack, unsigned int line_number)
{

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
