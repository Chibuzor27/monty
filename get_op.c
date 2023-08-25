#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void (*get_op(char *op))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"pop", _pop},
		{"pall", _pall},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"pint", _pint},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 6)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			return ((ops[i]).f);
		}
		i++;
	}

	dprintf(2, "Operation is not recognized\n");
	exit(EXIT_FAILURE);
}
