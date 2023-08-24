#include "monty.h"

/**
 * checkEmpty - ...
 * @buffer: the input
 *
 * Return: 1 if it is empty, meaning no commands
 * or arguments and only blank spaces, 0 otherwise
 */
int checkEmpty(char *buffer)
{
	int i;

	if (buffer[0] == '\0' || strcmp(buffer, "\n") == 0)
		return (1);
	for (i = 0; buffer[i]; i++)
		if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n')
			return (0);
	return (1);
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: ...
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t n = 0;
	int r_line;

	state = malloc(sizeof(state_t *));
	if (state == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	state->stack = malloc(sizeof(stack_t *));
	if (state->stack == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	state->line_counter = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	state->file = fopen(argv[1], "r");
	if (!state->file)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (state->line_counter++)
	{
		r_line = getline(&buffer, &n, state->file);
		if (r_line == -1) /* EOF */
		{
			free(buffer);
			break;
		}
		if (!checkEmpty(buffer))
			function_caller(buffer);
		free(buffer);
	}
	free_stack(state->stack);
	free(state);
	fclose(state->file);
	return (0);
}
