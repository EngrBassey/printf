#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>


int _printf(const char *format, ...);
int _putchar(char c);
void special_chr(const char c);
int handle_directive(char directive, va_list args, int *count);
int handle_binary_arg(va_list args);
int print_binary_arg(va_list args);
int print_string_arg(va_list args);
int print_integer_arg(va_list args);
int print_decimal_arg(va_list args);
int power_of_ten(int exponent);
void int_fun(int num);
void print_integer(int num);

#endif /* MAIN_H_ */
