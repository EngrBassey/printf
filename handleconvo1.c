#include "main.h"

/**
 * print_binary - Print an unsigned integer in binary format
 * @num: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int num)
{
if (num / 2)
print_binary(num / 2);

print_binary('0' + num % 2);

return (0);
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
count += print_binary(ch);
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
case 'b':
{
unsigned int num = va_arg(args, unsigned int);
count += print_binary(num);
break;
}
case '%':
count += print_binary('%');
break;
default:
count += print_binary('%');
count += print_binary(*format);
break;
}

return (count);
}
