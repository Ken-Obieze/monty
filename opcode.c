#include "monty.h"

/**
 * fetch_opcode - function matches function to opcode
 * @opcode: operationcode
 * @value: place value
 * @ln: line number
 * @format: function format
 */

void fetch_opcode(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t ops[] = {
		{"push", sta_push},
		{"pall", sta_pall},
		{"pint", sta_pint},
		{"pop", sta_pop},
		{"nop", sta_nop},
		{"swap", sta_swap},
		{"add", sta_add},
		{"sub", sta_sub},
		{"div", sta_div},
		{"mul", sta_mul},
		{"mod", sta_mod},
		{"pchar", sta_pchar},
		{"pstr", sta_pstr},
		{"rotl", sta_rotl},
		{"rotr", sta_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			call_fun(ops[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
				
}
