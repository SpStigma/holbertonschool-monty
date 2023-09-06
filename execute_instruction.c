#include "monty.h"

/**
 * exec_instruction - function to search for a correspondence
 * @stack: A pointer to a pointer to the stack
 * @opcode: The opcode to execute
 * @line_number: The line number in the file
 */
void exec_instruction(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop},
		{NULL, NULL}};

	for (int i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
	exit(EXIT_FAILURE);
}
