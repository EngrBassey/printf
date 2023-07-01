#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/** creating macros **/
#define UNUSED(y) (void)(y)
#define binary_size 32
#define octal_size 12

int _printf(const char *format, ...);

/** string function, char and lenght function proto **/
int _strlen(char *str);
int stringFun(va_list str);
int revstring(va_list str);
int c_char(va_list c);
int percent(va_list pr);
int _putchar(char c);
int s_char(va_list string);

/** integer function, binary func, unsigned, octal*/
int integer(va_list num);
int binar_num(va_list b);
int fun_num(int x);
int octal_num(va_list num);
int unsigned_num(va_list num);
int hex_num(va_list num);

#endif
