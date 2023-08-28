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

	if (av != NULL && av[1] != NULL)
	{
		interpret(&stack, av[1], 1024);
	}
	free_stack(&stack);

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
	ops_t *node, *next, *ops;
	int skip = -1;
	int (*op)(stack_t **, unsigned int);
	int res = 0;

	ops = readfile(filename, limit);
	if (ops == NULL)
		return;

	while (ops != NULL)
	{
		if (skip != -1 && ops->line_number != skip)
			skip = -1;
		if (skip == -1 && ops->opcode[0] == '#')
			skip = ops->line_number;
		if (skip == -1)
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
					free(next->opcode);
					free(next);
				}
			}
			else
			{
				op = get_op(ops->opcode, ops->line_number);
				if (op == NULL)
				{
					free_ops(&ops);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
				res = op(stack, ops->line_number);
				if (res == -1)
				{
					free_ops(&ops);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
			}
		}
		node = ops;
		ops = ops->next;
		node->next = NULL;
		free(node->opcode);
		free(node);
	}
}
