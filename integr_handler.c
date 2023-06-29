#include "main.h"
/**
 * _printf_o - octal
 * @arg: arg list
 * Return: number digits
 */
int _printf_o(va_list arg)
{
	unsigned int numb;
	int c = 0, k, result[12];

	numb = va_arg(arg, unsigned int);
	if (numb == 0)
	{
		_putchar('0');
		return (1);
	}
	while (numb != 0)
	{
		result[c] = numb % 8;
		numb /= 8;
		c++;
	}
	for (k = c - 1; k >= 0; k--)
	{
		_putchar(result[k] + '0');
	}
	return (c);
}

/**
 * fun_num - print number
 * @x: the number
 * Return: return  i
 */

int fun_num(int x)
{
	int i = 0;

	if (x / 10)
	{
		i += fun_num(x / 10);
	}

	_putchar((x % 10) + '0');
	i++;

	return (i);
}

/**
 * integer - function that handles %d and %i
 * @num: the number
 * Return: return count
 */

int integer(va_list num)
{
	int num_d = va_arg(num, int);
	int count = 0;

	if (num_d < 0)
	{
		_putchar('-');
		num_d = -num_d;
		count++;
	}
	if (num_d / 10)
		count += fun_num(num_d / 10);
	_putchar((num_d % 10) + '0');
	count++;
	return (count);
}
