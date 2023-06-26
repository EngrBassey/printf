#include "main.h"

/**
 * print_binary_arg - prints an unsigned int argument in binary
 * @args: variable argument list
 *
 * Return: the number of characters printed
 */

int print_binary_arg(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
int printed = 0;
int started = 0;

for (; mask > 0; mask >>= 1)
{
if (num & mask)
{
putchar('1');
started = 1;
printed++;
}
else if (started)
{
putchar('0');
printed++;
}
}
if (!started)
{
putchar('0');
printed++;
}

return (printed);
}
