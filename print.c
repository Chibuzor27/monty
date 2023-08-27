#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "monty.h"

/**
 * _puts - function to write string
 * @fd: the file descriptor
 * @s: the string
 *
 * Return: int
 */
int _puts(int fd, char *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (*(s + i) != '\0')
		{
			if (_putchar(fd, *(s + i)) == -1)
			{
				return (-1);
			}
			i++;
		}
	}

	return (i);
}

/**
 * _putn - writes to a file descriptor
 * @fd: the file descriptor
 * @n: the number
 * Return: int
 */
int _putn(int fd, unsigned int n)
{
	unsigned int zeros = 0;
	int digit = n;
	int div = n;

	if (n < 10)
	{
		_putchar(fd, n + '0');
	}
	else
	{
		while (div >= 10)
		{
			div = div / 10;
			zeros++;
		}

		while (n >= 10)
		{
			if (n <= (10 ^ zeros))
			{
				_putchar(fd, '0');
			}
			else
			{
				digit = (int)(n / (10 ^ zeros));
				_putchar(fd, digit + '0');
				n = n - (digit * (10 ^ zeros));
			}
			zeros--;
		}
		_putchar(fd, n + '0');
	}
	return (1);
}

/**
 * _putchar - write to file descriptor
 * @fd: the file descriptor
 * @c: the character
 * Return: int
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}
