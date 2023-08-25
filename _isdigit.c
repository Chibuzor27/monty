#include<stdio.h>

/**
 * _isdigit - check if a value is a digit
 * @text: arg
 *
 * Return: 1 if true
 */
int _isdigit(char *text)
{
	int i = 0;

	if (text == NULL)
	{
		return (0);
	}

	while (*(text + i) != '\0')
	{
		if (!(*(text + i) + 0 >= 48 && *(text + i) + 0 < 58))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

