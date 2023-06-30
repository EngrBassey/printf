#include "main.h"

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
count += write(STDOUT_FILENO, &ch, 1);
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
case 'u':
{
unsigned int num = va_arg(args, unsigned int);
count += print_unsigned_integer(num);
break;
}
case 'o':
{
unsigned int num = va_arg(args, unsigned int);
count += print_octal(num);
break;
}
case 'x':
{
unsigned int num = va_arg(args, unsigned int);
count += print_hexadecimal(num, 0);
break;
}
case 'X':
{
unsigned int num = va_arg(args, unsigned int);
count += print_hexadecimal(num, 1);
break;
}
case '%':
count += write(STDOUT_FILENO, "%", 1);
break;
default:
count += write(STDOUT_FILENO, "%", 1);
count += write(STDOUT_FILENO, format, 1);
break;
}

return (count);
}
