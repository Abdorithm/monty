#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - tokenize the input string.
 * @buffer: the input command.
 *
 * Return: a NULL-terminated array of strings {"cmd", "arg1", "arg2", NULL}.
 */
char **tokenize(char *buffer)
{
	char **args = NULL, *token, *tmp, *tmp_token;
	int size = 0, i;

	tmp = strdup(buffer);
	if (tmp == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp_token = strtok(tmp, " \t\n");
	while (tmp_token != NULL)
	{
		size++;
		tmp_token = strtok(NULL, " \t\n");
	}
	free(tmp), size++;
	args = (char **)malloc(sizeof(char *) * size);
	if (args == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < size - 1; i++)
	{
		token = strtok((i ? NULL : buffer), " \t\n");
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(args[i]);
			free(args);
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	args[size - 1] = NULL;
	return (args);
}

/**
 * choose_f - choose the function corresponding
 * to the opcode and call it.
 * @opcode: ...
 * @doubly_list: the stack or queue.
 * @n: the chosen function paramenter.
 */
void choose_f(char *opcode, int n, stack_t **doubly_list)
{
	int i;

	instruction_t instruction_type[] = { /* array of structs to choose from */
		{"push", push}, {"pall", print_all}, {"pint", print_top},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", do_nothing}, {NULL, NULL}
	};
	for (i = 0; instruction_type[i].opcode != NULL; i++)
		if (opcode == instruction_type[i].opcode)
			return (instruction_type[i].f(doubly_list, n));
}
