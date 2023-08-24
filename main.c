#include "monty.h"

state_t state = INIT_STATE;

/**
 * readLine - ...
 *
 * Return: pointer to the command
 */
char *readLine()
{
	char *line = NULL;
	size_t n = 0;
	int r_line;

	r_line = getline(&line, &n, state.file);
	if (r_line == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

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

	state.stack = NULL;
	state.line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}

	state.file = fopen(argv[1], "r");
	if (!state.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		buffer = readLine();
		state.line_counter++;
		if (buffer == NULL)
		{
			free(buffer);
			break;
		}
		if (checkEmpty(buffer))
		{
			free(buffer);
			continue;
		}
		function_caller(buffer);
		free(buffer);
	}
	fclose(state.file);
	free_stack(state.stack);
	return (0);
}
