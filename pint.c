#include "monty.h"

/**
 * sta_pint - prints top data
 * @stack: head of stack
 * @line_num: line indexer
 */

void sta_pint(stack_t **stack, unsigned int line_num)
{
        if (!stack || !(*stack))
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
                status = EXIT_FAILURE;
                return;
        }
        printf("%d\n", (*stack)->n);
}
