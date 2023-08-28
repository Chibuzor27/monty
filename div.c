#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _div - function to divide top two elements in stack
 * @stack: stack
 * @line_number: arg
 * Return: int
 */
int _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node = *stack;
		*stack = node->next;
		(*stack)->prev = NULL;
		if (node->n == 0)
		{
			dprintf(2, "L%d: division by zero\n", line_number);
			return (-1);
		}
		(*stack)->n = (*stack)->n / node->n;
		free(node);
	}
	else
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
