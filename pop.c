#include "monty.h"

/**
 * pop_stack - The opcode pop removes the top element of the stack.
 * @stack: The stack
 * @line_number:the line_number to display the error messages
 * 
*/
void pop_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    *stack = (*stack)->next;
    free(temp);
}