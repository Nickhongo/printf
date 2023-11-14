#include "main.h"

/**
 * _print_unsigned_int - Prints unsigned integer in binary, decimal or octal
 * @str: String whether to print in binary, octal or decimal
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int _print_unsigned_int(char *str, unsigned int n)
{
	unsigned int i = 0, start, end, temp_num = n, divisor;
	int len = 0;
	char *buffer, temp;

	if (str[i] == 'b')
		divisor = 2;
	else if (str[i] == 'o')
		divisor = 8;
	else
		divisor = 10;

	while (temp_num > 0)
	{
		len++;
		temp_num /= divisor;
	}
	buffer = malloc(len + 1);
	if (!buffer)
		return (0);
	while (n > 0)
	{
		buffer[i] == n % divisor + '0';
		n /= divisor;
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
