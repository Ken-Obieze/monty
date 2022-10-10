#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fctl.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void sta_swap(stack_t **stack, unsigned int line_num);
void sta_sub(stack_t **stack, unsigned int line_num);
void sta_rotr(stack_t **stack, unsigned int line_num);
void sta_rotl(stack_t **stack, unsigned int line_num);
int is_number(char *s);
void sta_push(stack_t **stack, unsigned int line_num);
void sta_pstr(stack_t **stack, unsigned int line_num);
void sta_pop(stack_t **stack, unsigned int line_num);
void sta_pint(stack_t **stack, unsigned int line_num);
void sta_pchar(stack_t **stack, unsigned int line_num);
void sta_pall(stack_t **stack, unsigned int line_num);
void fetch_opcode(char *opcode, char *value, int ln, int format);
void sta_nop(stack_t **stack, unsigned int line_cnt);
void sta_mul(stack_t **stack, unsigned int line_num);
void free_nodes(void);
int get_line(char *buff, int line_num, int format);
void read_opcode(FILE *fl);
void open_opcode(char *file);
int main(int argc, char *argv[]);
void sta_mod(stack_t **stack, unsigned int line_num);
void call_fun(op_func func, char *op, char *val, int ln, int format);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);
stack_t *add_node(int n);
stack_t *queue_node(stack_t **stack, const int n);
void sta_div(stack_t **stack, unsigned int line_num);
void sta_add(stack_t **stack, unsigned int line_num);


#endif
