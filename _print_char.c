#include "main.h"
/**
 * _print_character - prints a character
 * @c: character
 *
 * Return: length of character printed
 */
int _print_character(char c)
{
	return (write(1, &c, 1));
}
