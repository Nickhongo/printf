#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/* function prototypes */

int _print_character(char c);
int _print_string(char *str);
int _print_integer(int n);
int _print_unsigned_int(char *str, unsigned int n);
int _print_hex(char *str, unsigned int n);
int _print_address(void *address);
int _printf(const char *format, ...);

#endif /* MAIN_H */
