#include "monty.h"

/**
 *  getting_stream_failed - Handles the error when reading a file falls.
 *  @fileName: the name of the file that failed to open.
 */

void getting_stream_failed(char *fileName)
{
	dprintf(2, "Error: Can't open file %s\n", fileName);
	free_arguments();
	exit(EXIT_FAILURE);
}
/**
 * get_stream - gets the stream for reading from the specified file.
 * @fielName: Name of the file to open and set as the stream.
 */

void get_stream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		getting_stream_failed(fileName);

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		getting_stream_failed(fileName);
	}
}

/**
 * close_stream - closes file and sets it to null
 */
 
void close_stream(void)
{
	if(arguments->stream ==NULL)
		return;
	fclose(arguments->stream);
	arguments->stream = NULL;
}
