#include "main.h"

/**
  * string_func - function that handles %s
  * @str: the string
  * Return: return count
  */

int string_func(char *str)
{
	int i;
	int count = 0;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
			count = count + 1;
		}
	}
	else
	{
		_putchar('N');
		_putchar('U');
		_putchar('L');
		_putchar('L');

		count = 4;
	}

	return (count);
}
