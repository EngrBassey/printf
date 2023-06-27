#include "main.h"

/**
 * power_of_ten - calculates the power of 10 for a given exponent
 * @exponent: the exponent value
 *
 * Return: the power of 10 for the given exponent
 */
int power_of_ten(int exponent)
{
int result = 1;
int i;

for (i = 0; i < exponent; i++)
{
result *= 10;
}

return (result);
}

/**
 * handle_directive - handles the conversion directive
 * @directive: the conversion directive character
 * @args: the variable argument list
 * @count: pointer to the count of characters
 *
 * Return: the number of characters printed
 */
int handle_directive(char directive, va_list args, int *count)
{
int num, temp, digits, digit;
char ch;

switch (directive)
{
case 'd':
case 'i':
num = va_arg(args, int);
temp = num;
digits = 0;

if (num == 0)
{
putchar('0');
(*count)++;
}
else
{
if (num < 0)
{
putchar('-');
(*count)++;
temp = -temp;
}
while (temp > 0)
{
temp /= 10;
digits++;
}

while (digits > 0)
{
digit = (num / power_of_ten(digits - 1)) % 10;
ch = digit + '0';
putchar(ch);
(*count)++;
digits--;
}
}
break;

default:
putchar('%');
putchar(directive);
(*count) += 2;
break;
}

return (0);
}
