#include "monty.h"

/**
 * sta_mod - computes quotient
 * @stack: head of LL
 * @line_num: line indexer
 */

void sta_mod(stack_t **stack, unsigned int line_num)
{
        int result;

        if (!stack || !*stack || !((*stack)->next))
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
                status = EXIT_FAILURE;
                return;
        }
        if (((*stack)->n) == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        result = ((*stack)->next->n) % ((*stack)->n);
        pop(stack, line_num);
        (*stack)->n = result;
}
