#include "monty.h"

/**
 * open_file - Opens a file.
 * @filename: The name of the file to open.
 *
 * Return: A pointer to the opened file.
 */

FILE *open_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
