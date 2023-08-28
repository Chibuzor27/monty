#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * _nop - function to pop stack
 * @stack: stack
 * @line_number: arg
 * Return: 0
 */
int _nop(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL && line_number > 0)
	{
		return (0);
	}

	return (0);
}
