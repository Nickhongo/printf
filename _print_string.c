#include "main.h"

/**
 * _print_string - prints a string
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int _print_string(char *str)
{
	int len = 0, i = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}

	return (write(1, str, len));
}
