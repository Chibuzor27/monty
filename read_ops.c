#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

ops_t *add_op(ops_t **head, char *text, int n);
void create_op(char *word, int, ops_t **, ops_t **);

/**
 * read_ops - function to read line
 * @line: arg
 * @n: line number
 * Return: head node
 */
ops_t *read_ops(char *line, int n)
{
	int wc = 0;
	char word[6];
	int i = 0;
	ops_t *ops = NULL;
	ops_t *last = NULL;

	if (line == NULL)
	{
		return (NULL);
	}

	while (*(line + i) != '\0')
	{
		if (*(line + i) == ' ' && wc != 0)
		{
			word[wc] = '\0';
			create_op(word, n, &ops, &last);
			wc = 0;
			word[0] = '\0';
		}
		else if (*(line + i) != ' ')
		{
			word[wc] = *(line + i);
			wc++;
		}
		i++;
	}

	word[wc] = '\0';
	if (wc > 0)
	{
		create_op(word, n, &ops, &last);
	}

	return (ops);
}

/**
 * create_op - function
 * @word: arg
 * @n: arg
 * @head: arg
 * @last: arg
 */
void create_op(char *word, int n, ops_t **head, ops_t **last)
{
	ops_t *node = malloc(sizeof(ops_t));

	if (node != NULL)
	{
		node->opcode = malloc(sizeof(char) * strlen(word));
		if (node->opcode == NULL)
			return;
		strcpy(node->opcode, word);
		node->line_number = n;

		if (*head == NULL)
		{
			*head = node;
			*last = node;
		}
		else
		{
			(*last)->next = node;
			*last = (*last)->next;
		}
	}
}

/**
 * add_op - add operation node
 * @head: the head node
 * @text: the opcode
 * @n: line number
 * Return: last node
 */
ops_t *add_op(ops_t **head, char *text, int n)
{
	ops_t *node = NULL;
	ops_t *next = NULL;

	node = malloc(sizeof(ops_t));
	if (node == NULL)
	{
		return (NULL);
	}

	strcpy(node->opcode, text);
	node->line_number = n;
	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}

	next = *head;
	while (next->next != NULL)
	{
		next = next->next;
	}
	next->next = node;
	return (next);
}
