#include "monty.h"

/**
 * sta_swap -  swaps top data with penultimate
 * @stack:  pointr to head of LL
 * @line_num: line indexer
 */

void sta_swap(stack_t **stack, unsigned int line_num)
{
        stack_t *tmp = NULL;
        int i = 0;

        if (!stack || !*stack || !((*stack)->next))
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
                status = EXIT_FAILURE;
                return;
        }
        tmp = *stack;
        i = tmp->n;
        tmp->n = i;

        tmp->n = tmp->next->n;
        tmp->next->n = i;

}
