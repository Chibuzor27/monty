#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _pop - function to pop stack
 * @stack: stack
 * @line_number: arg
 * Return: int
 */
int _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*stack != NULL)
	{
		node = *stack;
		*stack = (*stack)->next;
		node->next = NULL;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		printf("%d\n", (node)->n);
		free(node);
	}
	else
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		return  (-1);
	}
	return (0);
}
