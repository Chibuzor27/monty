#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "monty.h"

void interpret(stack_t **stack, char *, int);

/**
 * main - entry point
 * @ac: arg count
 * @av: arg list
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	interpret(&stack, av[1], 1024);

	return (0);
}

/**
 * interpret - function
 * @stack: arg
 * @filename: arg
 * @limit: arg
 */
void interpret(stack_t **stack, char *filename, int limit)
{
	ops_t *node;
	ops_t *next;
	ops_t *ops;

	ops = readfile(filename, limit);
	if (ops == NULL)
	{
		return;
	}

	while (ops != NULL)
	{
		if (strcmp(ops->opcode, "push") == 0)
		{
			next = ops->next;
			if (next == NULL)
			{
				push(stack, NULL, ops->line_number);
			}
			else
			{
				push(stack, next->opcode, ops->line_number);
				ops->next = next->next;
				next->next = NULL;
				free(next);
			}
		}
		else
		{
			(get_op(ops->opcode, ops->line_number))(stack, ops->line_number);
		}
		node = ops;
		ops = ops->next;
		node->next = NULL;
		free(node);
	}
}
