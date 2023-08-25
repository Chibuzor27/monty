#include <stdio.h>

/**
 * _atoi - function
 * @str: arg
 *
 * Return: int
 */
int _atoi(char *str)
{
	int i = 0;
	int num = 0;

	if (str == NULL)
	{
		return (-1);
	}

	while (*(str + i) != '\0')
	{
		if (*(str + i) + 0 >= 48 && *(str + i) + 0 < 58)
		{
			num = num * 10 + ((*(str + i) + 0) - 48);
		}
		else
		{
			return (-1);
		}
		i++;
	}

	return (num);
}
