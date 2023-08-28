#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _pint - function to peek top of stack
 * @stack: stack
 * @line_number: arg
 * Return: int
 */
int _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		_putn(0, (*stack)->n);
		_puts(0, "\n");
	}
	else
	{
		_puts(2, "L");
		_putn(2, line_number);
		_puts(2, ": can't pint, stack empty\n");
		return (-1);
	}
	return (0);
}
