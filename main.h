#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int handle_directive(char directive, va_list args, int *count);
int print_string_arg(va_list args);
int print_binary_arg(va_list args);
int print_integer_arg(va_list args);
int print_decimal_arg(va_list args);
int power_of_ten(int exponent);
#endif /* MAIN_H_ */
