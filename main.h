#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <limits.h>
#include <string.h>
int _printf(const char *format, ...);
int _putchar(char c);
int strLen(char *size);
int lenStr_Ptr(const char *size);
int percentage_print(void);
int char_print(va_list character);
int string_print(va_list str);
#endif
