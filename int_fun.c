#include "main.h"

/**
  * int_fun - function that handles d and i format specifier
  * @num: the number
  */

void int_fun(int num)
{
	int n;

	if (num == 0)
	{
		return;
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	n = num / 10;

	int_fun(n);

	_putchar(num % 10 + '0');
}
