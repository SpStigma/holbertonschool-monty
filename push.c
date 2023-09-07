#include "monty.h"

/**
 * push_stack - Function to push a new node with a value on top
 * @stack: stack to push
 * @line_number: line number
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *New_top = malloc(sizeof(stack_t));

	if (New_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	char *rest_of_line = strtok(NULL, " \t");

	if (rest_of_line == NULL || integer_valid(rest_of_line) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	int number = atoi(rest_of_line);

	New_top->n = number;
	New_top->prev = NULL;
	New_top->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = New_top;
	}
	*stack = New_top;
}
