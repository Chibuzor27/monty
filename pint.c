#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _pint - function to peek top of stack
 * @stack: stack
 * @line_number: arg
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		dprintf(0, "%d\n", (*stack)->n);
	}
	else
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
