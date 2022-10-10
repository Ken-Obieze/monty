#include "monty.h"

/**
 * sta_pall - prints all values on stack
 * @stack: Pointer to head of LL
 * @line_num: line indexer
 */

void sta_pall(stack_t **stack, unsigned int line_num)
{
        stack_t *tmp = *stack;

        (void) line_num;
        while (stack && tmp)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}
