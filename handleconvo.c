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

int temp = num;
int digits = 0;
do {
temp /= 10;
digits++;
} while (temp != 0);

while (digits > 0)
{
int divisor = 1;
for (int i = 1; i < digits; i++)
divisor *= 10;

int digit = num / divisor;
count += _putchar('0' + digit);
num %= divisor;
digits--;
}

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
