#include "monty.h"

/**
 * main - Entry point for the Monty interpreter program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: 0 on success, or a non-zero value on failure.
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char ligne[MAX_LINE];
	char *filename = argv[1];
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = open_file(filename);

	while (fgets(ligne, sizeof(ligne), file))
	{
		size_t len = strlen(ligne);

		if (len > 0 && ligne[len - 1] == '\n')
			ligne[len - 1] = '\0';

		char *opcode = strtok(ligne, " \t");

		if (opcode == NULL)
		{
			line_number++;
			continue;
		}
		else
		{
			exec_instruction(&stack, opcode, line_number);
		}
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (0);
}

