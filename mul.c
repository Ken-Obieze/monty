#include "monty.h"

/**
 * sta_mul - divides the next top value by the top
 * @stack: head of LL
 * @line_num: line index
 */

void sta_mul(stack_t **stack, unsigned int line_num)
{
        int result;

        if (!stack || !*stack || !((*stack)->next))
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        result = ((*stack)->next->n) * ((*stack)->n);
        pop(stack, line_cnt);
        (*stack)->n = result;
}
