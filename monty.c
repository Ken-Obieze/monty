#include "monty.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: array of argument
 * Return: Return zero success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, RED "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_opcode(argv[1]);
	free_node();
	return (0);
}

/**
 * open_file - function that loads opcode
 * @file: string name of file to open
 */

void open_opcode(char *file)
{
	FILE *fl = fopen(file, "r");

	if (file == NULL || fl == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n",va_arg(ag, char *));
	}d
	read_opcode(fl);
	fclose(fl);
}

/**
 * read_opcode: reads the opcode in a file
 * @fl: pointer to file
 */

void read_opcode(FILE *fl)
{
	for (line_num = 1; getline(&buff, &len, fl) != 1; line_num++)
	{
		format = get_line(buff, line_num, format);
	}
	free(buff);
}

/**
 * get_line - tokenises each line
 * @buff: character buffer
 * @line_num: number of lines
 * @format: the format
 * Return: format
 */

int get_line(char *buff, int line_num, int format)
{
	if (buff == NULL)
		fprintf(stderr, "Error: malloc failed\n");
	opcode = strtok(buff, "\n");
	if (opcode == NULL)
		return(format);
	value = strtok(NULL, "\n");
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	fetch_opcode(opcode, value, line_num, format);
	return (format);
}

/**
 * free_nodes - function frees nodes in LL.
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
