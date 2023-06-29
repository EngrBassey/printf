#include "main.h"

/**
 * print_string - Print a null-terminated string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
int count = 0;
int i = 0;

while (str[i] != '\0')
{
count += write(STDOUT_FILENO, &str[i], 1);
i++;
}

return (count);
}

/**
 * _printf - Custom printf implementation
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
	return (-1);
format++;

switch (*format)
{
case 'c':
{
int ch = va_arg(args, int);
count += write(STDOUT_FILENO, &ch, 1);
break;
}
case 's':
count += print_string(va_arg(args, char *));
break;
case '%':
count += write(STDOUT_FILENO, "%", 1);
break;
default:
count += write(STDOUT_FILENO, "%", 1);
count += write(STDOUT_FILENO, format, 1);
break;
}
}
else
{
count += write(STDOUT_FILENO, format, 1);
}

format++;
}
va_end(args);
return (count);
}
