#include "main.h"
/**
 *  _printf - function that produces string specifier
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
			else if (*format == 'i')
			{
				int num_int = va_arg(argums, int);
				int num, frac = 1, dig, i = 1;
				int last_num = num_int % 10;

				num_int = num_int / 10;
				num = num_int;
				if (last_num < 0)
				{
					_putchar('-');
					num = -num;
					num_int = -num_int;
					last_num = -last_num;
					i++;
				}
				if (num > 0)
				{
					while (num / 10 != 0)
					{
						frac = frac * 10;
						num = num / 10;
					}
					num = num_int;
					while (frac > 0)
					{
						dig = num / frac;
						_putchar(dig + '0');
						num = num - (dig * frac);
						frac = frac / 10;
						i++;
					}
				}
				_putchar(last_num + '0');
				_putchar(i);
			
			}

                }
                format++;
        }
        va_end(argums);
        return (count);
}
