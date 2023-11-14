#include "main.h"

/**
 * _print_rot13 - Prints a string encoded in rot13
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int _print_rot13(char *str)
{
	int i = 0, j, len = 0;
	char *buffer;
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (str[i++])
		len++;

	buffer = malloc(len + 1);
	if (!buffer)
	{
		return (0);
	}

	for (i = 0; str[i]; i++)
	{
		 buffer[i] = str[i];
	}
	buffer[i] = '\0';

	for (i = 0; buffer[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (buffer[i] == letters[j])
			{
				buffer[i] = rot[j];
				break;
			}
		}
	}

	len = _print_string(buffer);
	free(buffer);
	return (len);
}
