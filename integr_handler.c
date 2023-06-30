#include "main.h"

/**
 * unsigned_num - octal function handler
 * @num: the octal num
 * Return: return Count
 */

int unsigned_num(va_list num)
{

	int unsCount = 0, i, unsDigits[12];
	unsigned int value;
	int count = 0;

	value = va_arg(num, unsigned int);

	if (value == 0)
	{
		unsDigits[0] = 0;
		unsCount = 1;
	}
	while (value != 0)
	{
		unsDigits[unsCount] = value % 10;
		value = value / 10;
		unsCount++;
	}

	for (i = unsCount - 1; i >= 0; i--)
	{
		count += _putchar(unsDigits[i] + '0');
	}
	return (count);
}

/**
 * hex_num - function handles %x and %X.
 * @num: the number
 * Return: return counter
 */

int hex_num(va_list num)
{
	int count = 0, i = 0, j;

	unsigned int value = va_arg(num, unsigned int);
	unsigned int temp = value;
	int *hexDig;

	while (value / 16 != 0)
	{
		value /= 16;
	count++;
	}

	hexDig = (int *)malloc(count * sizeof(int));

	while (i < count)
	{
		hexDig[i] = temp % 16;
		temp /= 16;
	i++;
	}

	for (j = count - 1; j >= 0; j--)
	{
		if (hexDig[j] > 9)
			hexDig[j] = hexDig[j] + 7;
		_putchar(hexDig[j] + '0');
	}

	free(hexDig);

	return (count);
}

/**
 * octal_num - octal function handler
 * @num: the octal num
 * Return: return Count
 */
int octal_num(va_list num)
{

	int octalCount = 0, i, octalDigits[12];
	unsigned int value;
	int count = 0;

	value = va_arg(num, unsigned int);

	if (value == 0)
	{
		octalDigits[0] = 0;
		octalCount = 1;
	}
	while (value != 0)
	{
		octalDigits[octalCount] = value % 8;
		value = value / 8;
		octalCount++;
	}

	for (i = octalCount - 1; i >= 0; i--)
	{
		count += _putchar(octalDigits[i] + '0');
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
	_putchar((value % 10) + '0');
	count++;
	return (count);
}
