#include "monty.h"

/**
 * pint_stack - function prints the value at the top of the stack,
 * followed by a new line.
 * @stack: the stack
 * @line_number: the line_number to display the error messages
 */
void pint_stack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
