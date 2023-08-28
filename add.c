#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _add - function to add top two elements in stack
 * @stack: stack
 * @line_number: arg
 * Return: int
 */
int _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node = *stack;
		*stack = node->next;
		(*stack)->prev = NULL;
		(*stack)->n = (*stack)->n + node->n;
		free(node);
	}
	else
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
