#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "monty.h"

void interpret(stack_t **stack, char *line, int ln);

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *line;
	size_t len = 0;
	ssize_t n;
	int ln = 0;
	stack_t *stack = NULL;

	while ((n = getline(&line, &len, stdin)) > -1)
	{
		if (n == 0)
			break;
		if (n == 1 && strcmp(line, "\n") == 0)
			continue;
		ln++;
		line[n - 1] = '\0';
		interpret(&stack, line, ln);
	}

	return (0);
}

/**
 * interpret - function
 * @stack: arg
 * @line: arg
 * @ln: arg
 */
void interpret(stack_t **stack, char *line, int ln)
{
	ops_t *node;
	ops_t *next;
	ops_t *ops;

	ops = read_ops(line, ln);
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
				push(stack, NULL, ln);
			}
			else
			{
				push(stack, next->opcode, ln);
				ops->next = next->next;
				free(next);
			}
		}
		else
		{
			(get_op(ops->opcode))(stack, ln);
		}
		node = ops;
		ops = ops->next;
		free(node);
	}
}
