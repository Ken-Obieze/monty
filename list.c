#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue node
 * @stack: pointer to head
 * @n: node index
 * Return: newly created node
 */

stack_t *queue_node(stack_t **stack, const int n)
{
        stack_t *new = malloc(sizeof(stack_t));
        stack_t *current = *stack;

        if (!new)
        {
                free(new);
                return (NULL);
        }
        new->n = n;

        if (!*stack)
        {
                new->next = NULL;
                new->prev = NULL;
                *stack = new;
                return (new);
        }

        while (current)
        {
                if (!current->next)
                {
                        new->next = NULL;
                        new->prev = current;
                        current->next = new;
                        break;
                }
                current = current->next;
        }

        return (new);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 * Return: newly created node
 */

stack_t *add_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 * Return: number of elements of the list
 */

size_t print_stack(const stack_t *stack)
{
        size_t c = 0;

        while (stack)
        {
                printf("%d\n", stack->n);
                stack = stack->next;
                c++;
        }

        return (c);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 */

void free_stack(stack_t *stack)
{
        stack_t *current = stack;
        stack_t *next;

        if (stack)
        {
                next = stack->next;
                while (current)
                {
                        free(current);
                        current = next;
                        if (next)
                                next = next->next;
                }
        }
}

/**
 * call_fun - function that calls operand
 * @func: pointer to function
 * @op: operand
 * @val: value
 * @ln: line index
 * @format: format
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = add_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			queue_node(&node, ln);
	}
	else
		func(&head, ln);
}
