#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <limits.h>
#include <string.h>
/**
 * struct format handle and convert
 * specifiers for the file printf
 *
 * @spec: char pointer
 * @form: type pointer used for
 * converting specifiers function
 */
typedef struct format
{
	char *spec;
	int (*form)();
} point;
int _putchar(char c);
int _printf(const char *format, ...);
int strLen(char *size);
int lenStr_Ptr(const char *size);
int percentage_print(void);
int char_print(va_list character);
int string_print(va_list str);
#endif
