#include "main.h"

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *buffer = NULL;
	File *fl_pd;
	size_t n = 0;
	size_t r_line = 1;
	unsigned int line_counter;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fl_pd = fopen(argv[1], "r");
	if (!fl_pd)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		r_line = getline(&buffer, &n, fl_pd);
		line_counter++;
		tokenizer(buffer, line_counter, fl_pd);
		free(buffer);
	}
	fclose(file);
	return (0);
}
