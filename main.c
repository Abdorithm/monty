#include "monty.h"

state_t state = INIT_STATE;


/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments vector
 */

int main(int argc, char *argv[])
{
	state_t *state;
	char *buffer = NULL;
	size_t r_line = 1, n = 0;

	state = malloc(sizeof(state_t));

	if(state == NULL)
		exit(EXIT_FAILURE);
	state->stack = malloc(sizeof(stack_t **));
	state->line_counter = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	state->file = fopen(argv[1], "r");
	if (!state->file)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		state->line_counter++;
		r_line = getline(&buffer, &n, state->file);

		if (r_line > 0)
			function_caller(buffer, state);
		free(buffer);
	}
	fclose(state->file);
	return (0);
}
