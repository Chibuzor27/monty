#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _push - function
 * @stack: arg
 * @line_number: arg
 */
void _push(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		*stack = malloc(sizeof(stack_t));
		if (*stack == NULL)
		{
			dprintf(2, "L%d: usage: push integer\n", line_number);
		}
	}
}

/**
 * push - function
 * @stack: arg
 * @strn: arg
 * @line_number: arg
 * Return: int
 */
int push(stack_t **stack, char *strn, unsigned int line_number)
{
	stack_t *node = NULL;
	int n = _atoi(strn);

	if (strn == NULL || n == -1)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		return (-1);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		return (-1);
	}
	else
	{
		memset(node, 0, sizeof(stack_t));
		node->n = n;

		if (*stack == NULL)
		{
			*stack = node;
		}
		else
		{
			(*stack)->prev = node;
			node->next = (*stack);
			*stack = node;
		}
	}
	return (0);
}
