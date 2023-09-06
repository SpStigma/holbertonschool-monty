#include "monty.h"

/**
 * free_stack - function to free the stack
 * @stack: the stack to free
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
