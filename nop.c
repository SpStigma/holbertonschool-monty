#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: The stack
 * @line_number: the line_number to display the error messages
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
