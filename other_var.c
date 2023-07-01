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
/**
  * s_char - functio that handles %S
  * @string: the string chars
  * Return: return count
  */
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

/**
  * address - function that handles address
  * @num: the variable to locate
  * Return: return count
  */

int address(va_list num)
{
	int i;
	void *ptr = va_arg(num, void *);

	unsigned long address = (unsigned long)ptr;
	int count = 0;

	count += _putchar('0');
	count += _putchar('x');

	for (i = sizeof(void *) * 2 - 1; i >= 0; i--)
	{
		unsigned long mask = 0xFUL << (i * 4);
		unsigned long hex = (address & mask) >> (i * 4);

		if (hex < 10)
			count += _putchar(hex + '0');
		else
			count += _putchar(hex - 10 + 'a');
	}

	return (count);
}
