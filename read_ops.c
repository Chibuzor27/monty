#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"

ops_t *add_op(ops_t **head, char *text, int n);
void create_op(char *word, int, ops_t **, ops_t **);

/**
 * readfile - function to read a file
 * @filename: the file name
 * @limit: the size to read per instance
 * Return: an instance of the head operation node
 */
ops_t *readfile(char *filename, size_t limit)
{
	int fd, n;
	int ln = 1;
	ops_t *ops = NULL;
	ops_t *last = NULL;
	char *text = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		_puts(2, "Error: Can't open file ");
		_puts(2, filename);
		_puts(2, "\n");
		exit(EXIT_FAILURE);
	}

	text = malloc((sizeof(char) * limit) + 1);
	if (text == NULL)
	{
		_puts(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	memset(text, 0, (sizeof(char) * limit) + 1);

	while ((n = read(fd, text, sizeof(char) * limit)) > 0)
	{
		read_ops(text, &ln, &ops, &last);
	}
	close(fd);
	free(text);
	return (ops);
}

/**
 * read_ops - function to read line
 * @line: arg
 * @n: line number
 * @ops: the head operation node
 * @last: the last node
 * Return: head node
 */
ops_t *read_ops(char *line, int *n, ops_t **ops, ops_t **last)
{
	int wc = 0;
	char word[30] = {0};
	int i = 0;

	if (line == NULL)
	{
		return (NULL);
	}

	while (*(line + i) != '\0')
	{
		if ((*(line + i) == ' ' || *(line + i) == '\n') && wc != 0)
		{
			word[wc] = '\0';
			if (!(wc == 1 && *(line + i - 1) == '\n') && wc > 0)
			{
				create_op(word, *n, ops, last);
			}
			wc = 0;
			word[0] = '\0';
			if (*(line + i) == '\n')
				*n = *n + 1;
		}
		else if (*(line + i) != ' ' && *(line + i) != '\n')
		{
			word[wc] = *(line + i);
			wc++;
		}
		else if (*(line + i) == '\n')
		{
			*n = *n + 1;
		}
		i++;
	}

	word[wc] = '\0';
	if (wc > 0)
	{
		create_op(word, *n, ops, last);
	}

	return (*ops);
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
	ops_t *node = NULL;

	node = malloc(sizeof(ops_t));
	memset(node, 0, sizeof(ops_t));
	if (node == NULL)
	{
		_puts(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		node->opcode = malloc((sizeof(char) * strlen(word)) + 1);
		if (node->opcode == NULL)
		{
			_puts(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		memset(node->opcode, 0, (sizeof(char) * strlen(word)) + 1);
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
