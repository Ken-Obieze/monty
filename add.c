#include "monty.h"

/**
 * sta_add - adds an element to the stack
 * @stack: Pointer to head of stack
 * @line_num: line indexer
 */

void sta_add(stack_t **stack, unsigned int line_num)
{
        int result;

        if (!stack || !*stack || !((*stack)->next))
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        result = ((*stack)->next->n) + ((*stack)->n);
        pop(stack, line_num);
        (*stack)->n = result;
}
