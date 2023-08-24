#include "monty.h"

/**
 * function_caller - call the right function
 * @buffer: the input command
 */
void function_caller(char *buffer)
{
	char **args = tokenize(buffer);

	/**
	 * after we get the command and its arguments
	 * we call choose_f to choose the right function
	 */
	choose_f(args[0], args[1]);
}

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
		fprintf(stderr, "Error: malloc failed\n");
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
		fprintf(stderr, "Error: malloc failed\n");
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
			fprintf(stderr, "Error: malloc failed\n");
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
 * @n: the chosen function paramenter.
 */
void choose_f(char *opcode, char *n)
{
	int i;

	instruction_t instruction_type[] = { /* array of structs to choose from */
		{"push", push}, {"pall", pall}, {"pint", top},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", do_nothing}, {NULL, NULL}
	};
	for (i = 0; instruction_type[i].opcode != NULL; i++)
		if (opcode == instruction_type[i].opcode)
			instruction_type[i].f(state->stack, state->line_counter);

	if (instruction_type[i].opcode == NULL)
		fprintf(stderr, "%d: unknown instruction %s\n", state->line_counter, opcode);
}
