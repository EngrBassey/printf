#include "main.h"

/**
 * print_integer - Print an integer
 * @num: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int num)
{
int count = 0;

if (num < 0)
{
count += _putchar('-');
num = -num;
}
if (num / 10)
count += print_integer(num / 10);
count += _putchar('0' + (num % 10));

return (count);
}

/**
 * handle_format - Handle a format specifier
 * @format: Format string
 * @args: Variable arguments list
 * @count: Current count of characters printed
 *
 * Return: Updated count of characters printed
 */
int handle_format(const char *format, va_list args, int count)
{
switch (*format)
{
case 'c':
{
int ch = va_arg(args, int);
count += putchar(ch);
break;
}
case 's':
count += print_string(va_arg(args, char *));
break;
case 'd':
case 'i':
{
int num = va_arg(args, int);
count += print_integer(num);
break;
}
case '%':
count += putchar('%');
break;
default:
count += putchar('%');
count += putchar(*format);
break;
}

return (count);
}
