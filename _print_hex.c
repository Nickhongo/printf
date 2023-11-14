#include "main.h"

/**
 * _print_hex - Prints hexadecimal representation of unsigned int
 * @str: Denotes whether hex is in lowercase or uppercase
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int _print_hex(char *str, unsigned int n)
{
	char *buffer, temp, c;
	unsigned int i = 0, start, end, temp_num = n;
	int len = 0;

	if (str[i] == 'h')
		c = 'a';
	else
		c = 'A';
	while (temp_num > 0)
	{
		len++;
		temp_num /= 16;
	}

	buffer = malloc(len + 1);
	if (!buffer)
		return (0);

	while (n > 0)
	{
		buffer[i] = (n % 16 > 9) ? n % 16 + c - 10 : n % 16 + '0';
		n /= 16;
		i++;
	}
	buffer[i] = '\0';

	start = 0;
	end = i;
	while (start < end)
	{
		temp = buffer[end - 1];
		buffer[end - 1] = buffer[start];
		buffer[start] = temp;
		start++;
		end--;
	}
	len = _print_string(buffer);
	free(buffer);
	return (len);
}
