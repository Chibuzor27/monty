#include <stdlib.h>
#include "main.h"

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
			free(node->opcode);
			free(node);
			node = *ops;
		}
	}
}
