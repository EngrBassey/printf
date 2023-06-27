#include "main.h"

/**
 * print_integer - Prints an integer value to the console.
 * @num: The integer value to be printed.
 */

void print_integer(int num)
{
char buffer[20];
int i = 0;

bool is_negative = false;
if (num < 0)
{
is_negative = true;
num = -num;
}

if (num == 0)
{
buffer[i++] = '0';
}
else
{
while (num > 0)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}
}

if (is_negative)
{
write(1, "-", 1);
}

while (i > 0)
{
write(1, &buffer[--i], 1);
}
}
