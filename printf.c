#include "main.h"

/**
 * _printf - custom printf function
 * @format: different specifiers
 * Return: return count
 */

int _printf(const char *format, ...)
{
	/* ARRAY OF SPECIFIERS and thier FUNCTIONS*/
	const char *var_spec[] = {"%c", "%s", "%%", "%d", "%i", "%o", "%b",
		"%u"};
	int (*var_name[])(va_list) = {c_char, stringFun, percent,
		integer, integer, octal_num, binar_num, unsigned_num};

	va_list printf;
	int i = 0, count = 0, j = 0, value = 0, buffer;

	va_start(printf, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		buffer = (sizeof(var_spec) / sizeof(var_spec[0])) - 1;
		value = 0;
		while (buffer >= 0)
		{
			j = 0;
			while (var_spec[buffer][j] != '\0' &&
			var_spec[buffer][j] == format[i + j])
			{j++; }
			if (var_spec[buffer][j] == '\0')
			{
				count += var_name[buffer](printf);
				i += j;
				value = 1;
				break;
			}
			buffer--;
		}
		if (!value)
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(printf);
	return (count);
}
