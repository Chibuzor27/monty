#include <stdlib.h>
#include "monty.h"

/**
 * free_ops - function
 * @ops: arg
 */
void free_ops(ops_t **ops)
{
	ops_t *node;

	if (ops != NULL)
	{
		node = *ops;
		while (node != NULL)
		{
			*ops = (*ops)->next;
			node->next = NULL;
			free(node->opcode);
			free(node);
			node = *ops;
		}
	}
}

/**
 * free_stack - function
 * @stack: arg
 */
void free_stack(stack_t **stack)
{
	stack_t *node;

	if (stack != NULL)
	{
		node = *stack;
		while (node != NULL)
		{
			*stack = (*stack)->next;
			node->next = NULL;
			free(node);
			node = *stack;
		}
	}
}
