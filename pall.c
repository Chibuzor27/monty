#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

/**
 * _pall - function to print stack
 * @stack: stack
 * @line_number: arg
 * Return: int
 */
int _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node != NULL && line_number > 0)
	{
		dprintf(0, "%d\n", node->n);
		while (node->next != NULL)
		{
			node = node->next;
			dprintf(0, "%d\n", node->n);
		}
	}

	return (0);
}
