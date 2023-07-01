#include "main.h"
/**
 * percent - function that handles % specifier
 * @pr: the % char
 * Return: return 1
 */
int percent(va_list pr)
{
	UNUSED(pr);
	_putchar('%');

	return (1);
}

int s_char(va_list string)
{
	int count = 0;
	char *str = va_arg(string, char*);

	while (*str != '\0')
	{
		if (*str == '\n')
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar('0');
			count += _putchar('A');
		}
		else
		{
			count += _putchar(*str);
		}
		str++;
	}

	return (count);
}
