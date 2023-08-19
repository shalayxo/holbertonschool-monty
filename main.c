#include "monty.h"

/**
 * main - checks if argc is valid, and sends file through handler function
 * @argc: the number of command line arguments.
 * @argv: pointer to an array of strings containing the command-line arguments.
 * Return: EXIT_FAILURE if count not 2, 0 If success.
 */
int main(int argc, char **argv)
{
	(void) argv;

	valid_argument(argc);

	return (0);
	
}	
