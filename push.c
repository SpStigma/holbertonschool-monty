#include "monty.h"

int PushValue;
/**
 * push_stack - Function to push a new node with a value on top
 * @stack: stack to push
 * @line_number: line number
 * 
*/
void push_stack(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *New_top = malloc(sizeof(stack_t));
    if (New_top == NULL)
    {
        perror("allocation failed");
        exit(EXIT_FAILURE);
    }

    New_top->n = PushValue;
    New_top->prev = NULL;
    New_top->next = *stack;

    if (*stack != NULL)
    {
          (*stack)->prev = New_top; 
    }
    *stack = New_top;
}