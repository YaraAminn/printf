#include "main.h"
/**
 *  _printf - function that produces string specifier
 *  @format: a pointer of type char
 *  Return: no of bytes success
 */
int _printf(const char *format, ...)
{
	convert_match func_arr[] = {
	{"%%",percentage_print}, {"%c", char_print},{"%s", string_print},
        };

        va_list argums;
        int indx, j, lenth = 0;
	
	va_start(argums, format);
        if (format == NULL || (format[0] == '%' && format[1] == '\0'))
         /* check if format ptr is null or 1st indx inside format
          * is % and the 2nd contain nothing */
		return (-1); /* return error */
check_Inside_format:

        while (format[indx] != '\0')
        {
	 	j = 3;
                while (j >= 0)
                {
                        if (func_arr[j].spec[0] == format[indx] && func_arr[j].spec[1] == format[indx+1])
                        {
                                lenth = lenth + func_arr[j].form(argums);
                        }
                        indx = indx + 2;
                        goto check_Inside_format;
                }
                j--;
                _putchar(format[indx]);
                lenth++;
                indx++;
        }
        va_end(argums);
        return(lenth);
}
