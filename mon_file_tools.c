#include "monty.h"
/**
 * mon_file_open - opens a file
 * @file_name: file name path
 */
void file_opener(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		err(2, file_name);
	}
	mon_read_file(fd);
	fclose(fd);
}

/**
 * line_parser - parses a line of text and extract codeop and value tokens
 * @buff: line of text to parse
 * @ine_num: line number
 * @format: current storage format
 * Return: the updated format after parsing the line
 */
int line_parser(char *buff, int line_num, int format)
{
	char *val, *opcode;
	const char *del = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, del);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(opcode,"stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_my_func(opcode, val, line_num, format);
	return (format);
}

/**
 * mon_read_file - reads a file
 * @fd: file descriptor pointer
 * Return: void
 */
void mon_read_file(FILE *fd)
{
	int line_num, format = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buff, &len, fd) != -1; line_num++)
	{
		format = line_parser(buff, line_num, format);
	}
	free(buff);
}

/**
 * find_my_func - find the need function
 * @codeop: codeop
 * @val: arg of codeop
 * @en: entire line number
 * @format: storage format
 */
void find_my_func(char *opcode, char *val, int en, int format)
{
	int flags;
	int j;

	instruction_t func_list[] = {
		{"push", add_to_stack}, {"pall", print_my_stack},
		{"pint", top_print}, {"pop", pop_on_top},
		{"nop", nop}, {"swap", nodeswap},
		{"add", node_add}, {"sub", node_sub},
		{"div", node_div}, {"multi", multi_nodes},
		{"mode", mode_node}, {"pchar", char_print},
		{"pstr", string_prints}, {"rot1", rot1},
		{"rotr", rotr}, {NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flags = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_my_func(func_list[j].f, opcode, val, en, format);
			flags = 0;
		}
	}
	if (flags == 1)
		err(3, en, opcode);
}

/**
 * call_my_func - call the required function
 * @func: called function pointer
 * @op: rep op code
 * @val: rep numeric value
 * @en: intruction line number
 * @format: format specifier
 * Return: void
 */
void call_my_func(op_func func, char *op, char *val, int en, int format)
{
	stack_t *my_node;
	int flags;
	int i;

	flags = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flags = -1;
		}
		if (val == NULL)
		{
			err(5, en);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, en);
		}
		
		my_node = make_node(atoi(val) * flags);
		if (format == 0)
			func(&my_node, en);
		if (format == 1)
			add2queue(&my_node, en);
	}
	else
		func(&head, en);

	}
