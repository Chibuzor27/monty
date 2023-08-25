#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _swap - function to swap top two elements in stack
 * @stack: stack
 * @line_number: arg
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *next = NULL;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		node = *stack;
		next = (*stack)->next;

		next->next->prev = node;
		node->next = next->next;
		next->prev = NULL;
		next->next = node;
		node->prev = next;

		*stack = next;
	}
	else
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
