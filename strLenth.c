#include "main.h"
/**
 * strLen - function to get length of string
 * @size: char pointer
 *
 * Return: i success
 */
int strLen(char *size)
{
	int i;

	for (i = 0; size[i] != 0; i++)
		;
	return (i);
}

/**
 * lenStr_Ptr - function to get the size of
 * the size pointer which is constant
 *
 * @size: char pointer const
 * Return: j success
 */
int lenStr_Ptr(const char *size)
{
	int j;

	for (j = 0; size[j] != 0; j++)
		;
	return (j);
}
