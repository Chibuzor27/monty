#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _nop - function to pop stack
 * @stack: stack
 * @line_number: arg
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL && line_number > 0)
	{
		return;
	}
}
