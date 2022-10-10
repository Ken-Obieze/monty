#include "monty.h"

/**
 * sta_push - push element onto stack
 * @stack: head of LL
 * @line_num: line indexer
 */

void sta_push(stack_t **stack, unsigned int line_num)
{
        char *n = global.argument;

        if ((is_digit(n)) == 0)
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_num);
                status = EXIT_FAILURE;
                return;
        }

        if (global.data_struct == 1)
        {
                if (!add_node(stack, atoi(global.argument)))
                {
                        return;
                        status = EXIT_FAILURE;
                }
        }
        else
        {
                if (!queue_node(stack, atoi(global.argument)))
                {
                        return;
                        status = EXIT_FAILURE;
                }
        }
}

/**
 * is_number - checks if a string is composed of numbers
 * @s: string
 * Return: 1 if string has only numbers, 0 if not
 */

int is_number(char *s)
{
        if (!s)
                return (0);

        if (*s == '-')
                s++;

        for (; *s; s++)
                if (!isdigit(*s))
                        return (0);
        return (1);
}
