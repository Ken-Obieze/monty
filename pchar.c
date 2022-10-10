#include "monty.h"

/**
 * sta_pchar - prints the int value at the top of stack as char
 * @stack: head of LL
 * @line_num: line indexer
 */

void sta_pchar(stack_t **stack, unsigned int line_num)
{
        if (!stack || !(*stack))
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
                status = EXIT_FAILURE;
                return;
        }
        if (isascii((*stack)->n) == 0)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
                status = EXIT_FAILURE;
                return;
        }
        printf("%c\n", (*stack)->n);
}
