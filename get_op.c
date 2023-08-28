#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * get_op - function
 * @op: the operation code
 * @ln: line number
 * Return: function
 */
int (*get_op(char *op, unsigned int ln))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"pop", _pop},
		{"pall", _pall},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"pint", _pint},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 10)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			return ((ops[i]).f);
		}
		i++;
	}

	if (op[0] == '#')
	{
		return (_nop);
	}

	dprintf(2, "L%d: unknown instruction %s\n", ln, op);
	return (NULL);
}
