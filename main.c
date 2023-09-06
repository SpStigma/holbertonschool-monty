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
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(ligne, sizeof(ligne), file))
	{
		size_t len = strlen(ligne);

		if (len > 0 && ligne[len - 1] == '\n')
			ligne[len - 1] = '\0';

		char *opcode = strtok(ligne, " ");
		char *rest_of_line = strtok(NULL, " ");

		if (rest_of_line != NULL)
			PushValue = atoi(rest_of_line);

		exec_instruction(&stack, opcode, line_number);
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
