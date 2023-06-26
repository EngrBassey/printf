#include "main.h"

/**
  * _printf - printf custom function
  * @format: all format specifiers
  * Return: return count
  */

int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list printf;

	va_start(printf, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(printf, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			string_func(va_arg(printf, char *));
			i++;
			count = count + (count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
		{
			int_fun(va_arg(printf, int));
			i++;
		}
		else if (format[i + 1] != '\0')
		{
			special_chr(format[i + 1]);
			i++;
		}
		count += 1;
		i++;
	}
	return (count);
}

/**
  * special_chr - function that prints unpecified format
  * @c: the char
  */

void special_chr(char c)
{
	_putchar('%');
	_putchar(c);
}
