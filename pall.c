#include "monty.h"

/**
 * pall_stack - Function to print the stack
 * @stack: stack to be printed
 * @line_number: line number
 * 
*/
void pall_stack(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    } 
}