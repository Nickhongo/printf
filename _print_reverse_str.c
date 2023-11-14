#include "main.h"

/**
 * _print_reverse_str - Prints a string in reverse
 * @str: String to print in reverse
 *
 * Return: Number of characters printed
 */
int _print_reverse_str(char *str)
{
	int len = 0, i = 0, end;
	char *buffer;

	while (str[i++])
		len++;

	buffer = malloc(len + 1);
	if (!buffer)
		return (0);

	end = len - 1;
	i = 0;
	while (end >= 0)
	{
		buffer[i] = str[end];
		i++;
		end--;
	}
	buffer[i] = '\0';

	len = _print_string(buffer);
	free(buffer);
	return (len);
}
