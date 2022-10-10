#include "monty.h"

/**
 * sta_pstr - prints the contents of a stack_t stack as a string
 * @stack: pointer to head of stack
 * @line_num: line indexer
 */

void sta_pstr(stack_t **stack, unsigned int line_num)
{
        stack_t *tmp = *stack;

	(void) line_num;
        while (tmp)
        {
                if (tmp->n <= 0 || tmp->n > 127)
                        break;
                putchar((char) tmp->n);
                tmp = tmp->next;
        }
        putchar('\n');
}
