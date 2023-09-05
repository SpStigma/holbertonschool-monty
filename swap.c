#include "monty.h"
/**
 * swap_stack - The opcode swap swaps the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line_number to display the error messages
*/
void swap_stack(stack_t **stack, unsigned int line_number)
{
    int temp = 0;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}