#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _pop - function to pop stack
 * @stack: stack
 * @line_number: arg
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*stack != NULL)
	{
		node = *stack;
		*stack = (*stack)->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		dprintf(0, "%d\n", (node)->n);
		free(node);
	}
	else
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
