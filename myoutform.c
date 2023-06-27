
#include "main.h"

/**
 * _printf - produces output according to the format
 * @format: character string composed of 0 or more directives
 *
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '%')
{
write(1, "%", 1);
count++;
}
else if (*format == 'c')
{
int ch = va_arg(args, int);
write(1, &ch, 1);
count++;
}
else if (*format == 's')
{
count += print_string_arg(args);
}
else
{
write(1, "%", 1);
write(1, format, 1);
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
 * print_string_arg - prints a string argument
 * @args: variable argument list
 *
 * Return: the number of characters printed
 */
int print_string_arg(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;
int i = 0;

while (str[i])
{
write(1, &str[i], 1);
count++;
i++;
}
return (count);
}
