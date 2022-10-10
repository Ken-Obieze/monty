#include "monty.h"

/**
 * sta_sub -  substracts first two nodes of stack
 * @stack: pointer to hesd of LL
 * @line_num: line indexer
 */

void sta_sub(stack_t **stack, unsigned int line_num)
{
        int result;

        if (!stack || !*stack || !((*stack)->next))
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        result = ((*stack)->next->n) - ((*stack)->n);
        pop(stack, line_num);
        (*stack)->n = result;
}
