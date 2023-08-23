#include "monty.h"

state_t state = INIT_STATE;

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments vector
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *buffer = NULL;
	FILE *fl_pd;
	size_t n = 0;
	size_t r_line = 1;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fl_pd = fopen(argv[1], "r");
	state.file = fl_pd;
	state.stack = stack;
	if (!fl_pd)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		r_line = getline(&buffer, &n, fl_pd);
		line_counter++;
		if (r_line > 0)
			function_caller(buffer, &state);
		free(buffer);
	}
	state.line_counter = line_counter;
	fclose(fl_pd);
	return (0);
}
