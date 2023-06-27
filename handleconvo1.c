#include "main.h"

/**
 * handle_binary_arg - handles the binary conversion specifier
 * @args: variable argument list
 *
 * Return: the number of characters printed
 */
int handle_binary_arg(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0;
int binary[32];
int i;

for (i = 0; i < 32; i++)
{
binary[i] = num & 1;
}

for (i = 31; i >= 0; i--)
{
putchar('0' + binary[i]);
count++;
}

return (count);
}
