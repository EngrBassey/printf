#include "main.h"
/**
 * octal_num - octal function handler
 * @num: the octal num
 * Return: return count
 */
int octal_num(va_list num)
{

	int count = 0, i, digits[12];
	unsigned int value;

	value = va_arg(num, unsigned int);

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}
	while (value != 0)
	{
		digits[count] = value % 8;
		value = value / 8;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(digits[i] + '0');
	}
	return (count);
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
	int value = va_arg(num, int);
	int count = 0;

	if (value < 0)
	{
		_putchar('-');
		value = -value;
		count++;
	}
	if (value / 10)
	{
		count += fun_num(value / 10);
	}
	else
		_putchar((value % 10) + '0');
		count++;
	return (count);
}
