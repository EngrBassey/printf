#include "main.h"

/**
 * _printf - produces output according to the format
 * @format: character string composed of 0 or more directives
 *
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{	format++;
			if (*format == '%')
			{	write(1, "%", 1);
				count++;
			}
			else if (*format == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				count += print_string_arg(args);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int_fun(va_arg(args, int));
				count++;
			}
			else
			{
				special_chr(*format);
				count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
	format++;
	}
	va_end(args);
	return (count);
}
/**
 * print_string_arg - prints a string argumentint count = 0
 * @args: variable argument lisT
 * Return: the number of characters printed
 */
int print_string_arg(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int j = 0;

	if (str)
	{
		while (str[j])
		{
			write(1, &str[j], 1);
			count++;
			j++;
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

/**
  * special_chr - function that prints unspecifed format
  * @c: character
  */

void special_chr(const char c)
{
	_putchar('%');
	_putchar(c);
}

/**
  * int_fun - function that checks for %i and %d
  * @num: the number
  */

void int_fun(int num)
{
	int n;

	if (num == 0)
	{
		return;
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	n = num / 10;
	int_fun(n);

	_putchar(num % 10 + '0');
}
