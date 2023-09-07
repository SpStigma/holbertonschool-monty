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

		if (len == 0 || ligne[0] == '\0')
		{
			continue;
		}		
		char *opcode = strtok(ligne, " \t");
		char *rest_of_line = strtok(NULL, " \t");

		if (rest_of_line != NULL)
		{
			int lenght = strlen(rest_of_line);
			int i = 0;

			for( i = 0; i < lenght ; i++)
			{
				if (!isdigit(rest_of_line[i]) && rest_of_line[i] != '-')
				{
            		fprintf(stderr, "L%d: usage: push integer\n", line_number);
            		fclose(file);
            		free(stack);
            		exit(EXIT_FAILURE);
				}
			}
			PushValue = atoi(rest_of_line);
	
		}
		exec_instruction(&stack, opcode, line_number);
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
