#include "main.h"
/**
 *  _printf - function that produces output
 *  according to a format
 *  @format: a pointer of type char
 *  Return: no of bytes success
 */
int _printf(const char *format, ...)
{
        int count = 0;
        va_list argums;

        if (format == NULL)
                return (-1);

        va_start(argums, format);

         /** inspect the whole strings in format pointer */
        while (*format)
        {
                if (*format != '%') /* check if format strings
                not equal the percent sign */
                {
                        write(1,format,1); /* write standard output */
                        count++;
                }
                else
                {
                        format++; /* go to check the nxt character */
                        if (*format == '\0')
                                break; /** exit */
                        /** if the cond is 2 percent signs '%%' */
                        if (*format == '%')
                        {
                                write(1,format,1); /** print double '%%' */
                                count++;
                        }
                        /* to check for the 'c' characyer */
                        else if (*format == 'c')
                        {
                                char c = va_arg(argums, int);
                                /* where va_arg holds (argums,char) */
                                write(1,&c,1);
                                count++;
                        }
			else if (*format == 's')
                                /* check 's' condition */
                        {
                                char *str_check = va_arg(argums, char*);
                                int len_str = 0;

                                /* getting the string length */
                                while (str_check[len_str] != '\0')
                                        len_str++;
                                /* get the output string */
                                write(1,str_check,len_str);
                                count = count + len_str;
                        }

                }
                format++;
        }
        va_end(argums);
        return (count);
}
