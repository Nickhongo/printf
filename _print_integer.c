#include "main.h"

/**
 * _print_integer - Prints signed integer
 * @n: Integer tp print
 *
 * Return: Number of characters printed
 */
int _print_integer(int n)
{
	char *buffer, temp;
	int i = 0, start, end, len = 0, temp_num;

	if (n == 0)
		return (_print_character('0'));
	temp_num = (n < 0) ? -n : n;
	while (temp_num > 0)
	{
		len++;
		temp_num /= 10;
	}

	buffer = (n < 0) ? malloc((len + 2)) : malloc(len + 1);
	if (!buffer)
		return (0);
	if (n < 0)
	{
		buffer[i++] = '-';
		n = -n;
	}

	while (n > 0)
	{
		buffer[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	buffer[i] = '\0';

	start = (buffer[0] == '-') ? 1 : 0;
	end = i;
	while (start < end)
	{
		temp = buffer[end - 1];
		buffer[end - 1] = buffer[start];
		buffer[start] = temp;
		start++;
		end--;
	}
	len = (_print_string(buffer));
	free(buffer);
	return (len);
}
