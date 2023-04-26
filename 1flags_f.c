#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * _printf - _printf function prints a formatted string to the std output
 * supports various format specifiers such as:
 * %c, %s, %d, %u, %o, %x, %X, and %p
 * @format: A string that specifies the format of the output
 *
 * @Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						putchar(c);
						num_chars_printed++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							num_chars_printed++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						num_chars_printed++;
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						num_chars_printed += printf("%d", num);
						break;
					}
				case 'u':
					{
						unsigned int num = va_arg(args, unsigned int);
						num_chars_printed += printf("%u", num);
						break;
					}
				case 'o':
					{
						unsigned int num = va_arg(args, unsigned int);
						num_chars_printed += printf("%o", num);
						break;
					}
				case 'x':
				case 'X':
					{
						unsigned int num = va_arg(args, unsigned int);
						num_chars_printed += printf((*format == 'x') ? "%x" : "%X", num);
						break;
					}
				case 'p':
					{
						void *addr = va_arg(args, void *);
						num_chars_printed += printf("%p", addr);
						break;
					}
				default:
					{
						putchar('%');
						putchar(*format);
						num_chars_printed += 2;
						break;
					}
			}
		}
		else
		{
			putchar(*format);
			num_chars_printed++;
		}
		format++;
	}

	va_end(args);

	return num_chars_printed;
}
