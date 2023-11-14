#include "main.h"

/**
 * _print_address - Prints address
 * @address: Address (named location)
 *
 * Return: Number of characters printed
 */
int _print_address(void *address)
{
	char *buffer, temp;
	unsigned long n;
	int len, i = 0, start, end;

	n = (unsigned long) address;
	buffer = malloc(15);
	if (!buffer)
		return (0);

	buffer[i++] = '0';
	buffer[i++] = 'x';

	while (n > 0)
	{
		buffer[i] = (n % 16 > 9) ? n % 16 + 'a' - 10 : n % 16 + '0';
		n /= 16;
		i++;
	}
	buffer[i] = '\0';

	start = 2;
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
