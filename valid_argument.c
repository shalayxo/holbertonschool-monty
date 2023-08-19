#include "monty.h"

/**
 * valid_argument -checks the number of command-line arguments
 * @argc: The number of command-line arguments.
 * /

 void valid_argument(int argc)
 {
 	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
