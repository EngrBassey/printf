#include "main.h"
/**
 * binar_num - function that handles digits to binaries
 * @b: num
 * Return: return binary
 */
int binar_num(va_list b)
{
	unsigned int value;
	int binary;
	int i = 0, size[binary_size];

	value = va_arg(b, unsigned int);
	while (value == 0)
	{
		_putchar('0');
		return (1);
	}
	while (value != 0)
	{
		size[i]  = value % 2;
		value = value / 2;
		i++;
	}
	binary = i - 1;

	while (binary >= 0)
	{
		_putchar(size[binary] + '0');
		binary--;
	}
	return (i);
}
