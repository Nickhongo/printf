#include "main.h"

/**
 * _printf - Formats and prints data
 * @format: Format string that contains
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				len += _print_character(va_arg(args, int));
				i++;
				break;
			case 's':
				len += _print_string(va_arg(args, char *));
				i++;
				break;
			case '%':
				len += _print_character('%');
				i++;
				break;
			case 'u':
				len += _print_unsigned_int("dec", va_arg(args, unsigned int));
				i++;
				break;
			case 'o':
				len += _print_unsigned_int("oct", va_arg(args, unsigned int));
				i++;
				break;
			case 'b':
				len += _print_unsigned_int("bin", va_args(args, unsigned int));
				i++;
				break;
			default:
				_print_character('%');
				break;
			}
		}
		else
			len += _print_character(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
