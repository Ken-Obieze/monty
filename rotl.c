#include "monty.h"

/**
* sta_rotl - rotates first element of the stack
* @stack: pointer to head of LL
* @line_num: line indexer
*/

void sta_rotl(stack_t **stack, unsigned int line_num)
{
        stack_t *lft;
        stack_t *rgt;

        (void) line_num;
        if (!stack || !*stack || !(*stack)->next)
                return;

        lft = rgt = *stack;

        while (right->next)
                rgt = rgt->next;
        rgt->next = lft;
        lft->prev = rgt;
        *stack = lft->next;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
}
