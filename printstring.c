#include "main.h"
/**
 * string_print - function to print string specifier
 *
 * @str: input argument
 * Return: length of string
 */
int string_print(va_list str)
{
	char *s;
	int i;
	int length;

	s = va_arg(str, char *);
	if (s == NULL)
	{
		s = "(Nothing)";
		length = strlen(s);
		for (i = 0; i < length; i++)
		{
			_putchar([i]);
		}
		return (length);
	}
	else
	{
		length = strLen(s);
		for (i = 0; i < length; i++)
		{
			_putchar(s[i]);
		}
		return (length);
	}
}
