#include "main.h"

/**
 * c_char - function that handles all characters
 * @c: my character
 * Return: return 1 on success
 */

int c_char(va_list c)
{
	char charc = (char)va_arg(c, int);

	_putchar(charc);
	return (1);
}

/**
 * stringFun - handles the string function
 * @str: my string
 * Return: return j
 */

int stringFun(va_list str)
{
	char *ptr;
	int i, j;

	ptr = va_arg(str, char*);

	if (str = NULL || ptr == NULL)
	{
		ptr = "(null)";
	}

	j = _strlen(ptr);

	i = 0;
	while (i < j)
	{
		_putchar(ptr[i]);
		i++;
	}

	return (j);
}

/**
 * revstring - function that handles string reversal
 * @str: the string
 * Return: str I am returning
 */

int revstring(va_list str)
{
	char *ptr;
	int i, j;

	ptr = va_arg(str, char*);

	if (ptr == NULL)
	{
		ptr = "(null)";
	}
	for (j = 0; ptr[j] != '\0'; j++)
		;
	i = j - 1;

	while (i >= 0)
	{
		_putchar(ptr[i]);
		i--;
	}

	return (i);
}
/**
 * _strlen - function that gets the string length
 * @str: my string pointer
 * Return: retrun i
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
