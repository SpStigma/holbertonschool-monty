#include "monty.h"

/**
 * add_stack - The opcode add adds the top two elements of the stack.
 * @stack: The stack
 * @line_number: The opcode add adds the top two elements of the stack.
*/
void add_stack(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n += (*stack)->n;
    pop_stack(stack, line_number);
}