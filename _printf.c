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
	char *str;

	if (format == NULL)
		return (0);

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
				str = va_arg(args, char *);
				if (str == NULL)
					len += _print_string("(null)");
				else
					len += _print_string(str);
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
				len += _print_unsigned_int("bin", va_arg(args, unsigned int));
				i++;
				break;
			case 'x':
				len += _print_hex("hex", va_arg(args, unsigned int));
				i++;
				break;
			case 'X':
				len += _print_hex("HEX", va_arg(args, unsigned int));
				i++;
				break;
			case 'p':
				len += _print_address(va_arg(args, void *));
				i++;
				break;
			case 'd':
			case 'i':
				len += _print_integer(va_arg(args, int));
				i++;
				break;
			case 'R':
				len += _print_rot13(va_arg(args, char *));
				i++;
				break;
			case 'r':
				len += _print_reverse_str(va_arg(args, char *));
				i++;
				break;
			case '\0':
				break;
			default:
				len += _print_character('%');
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
