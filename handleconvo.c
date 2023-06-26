#include "main.h"

/**
 * print_decimal_arg - prints an integer argument
 * @args: variable argument list
 *
 * Return: the number of characters printed
 */
int print_decimal_arg(va_list args)
{
int num = va_arg(args, int);
return (printf("%d", num));
}

/**
 * print_integer_arg - prints an integer argument
 * @args: variable argument list
 *
 * Return: the number of characters printed
 */
int print_integer_arg(va_list args)
{
int num = va_arg(args, int);
return (printf("%d", num));
}
