#include "monty.h"

arg_t *arguments = NULL;

/**
 * main - Entry point
 * @argc: the number of command line arguments.
 * @argv: pointer to an array of strings containing the command-line arguments.
 * Return: 0 If success.
 */

int main(int argc, char **argv)
{
	size_t n = 0;

	valid_argument(argc);
	set_arguments();
	get_stream(argv[1]);

	while (getline(&arguments->command, &n, arguments->stream) != -1)
	{
	arguments->line_number += 1;
	tokenize_command();
	get_instruction();
	run_instruction();
	free_tokens();
	}

	close_stream();
	free_arguments();

	return (0);
}
