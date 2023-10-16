#include "main.h"
/**
 * char_print - function to print the
 * character specifier
 *
 * @character: argument
 *
 * Return: 1 success
 */
int char_print(va_list character)
{
	char charact;

	charact = va_arg(character, int);
	_putchar(charact);
	return (1);
}
