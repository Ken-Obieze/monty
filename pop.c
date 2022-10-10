#include "monty.h"

/**
 * sta_pop - pops top most value
* @stack: head of LL
* @line_num: line indexer*
*/

void sta_pop(stack_t **stack, unsigned int line_num)
{
        stack_t *tmp = NULL;

        if (!stack || !*stack)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
        if (!*stack)
                return;
	(*stack)->prev = NULL;
}
