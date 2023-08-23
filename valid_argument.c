#include "monty.h"

/**
 * valid_argument -checks the number of command-line arguments
 * @argc: The number of command-line arguments.
 */

void valid_argument(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * set_arguments - assigns a pointer to the arg_s structure
*/

void set_arguments(void)
{
arguments = malloc(sizeof(arg_t));
if (arguments == NULL)
	malloc_failed();

arguments->instruction = malloc(sizeof(instruction_t));
if (arguments->instruction == NULL)
	malloc_failed();

arguments->stream = NULL;
arguments->head = NULL;
arguments->command = NULL;
arguments->tokencnt = 0;
arguments->line_number = 0;
arguments->stack_len = 0;
arguments->stack = 1;
}
