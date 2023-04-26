#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int len = 0;

	while (*str)
	{
		putchar(*str++);
		len++;
	}
	return (len);
}
/**
 * print_number - Prints an integer.
 * @n: The integer to print.
 *
 * Return: The number of digits printed.
 */
int print_number(int n)
{
	int len = 0;

	if (n < 0)
	{
		putchar('-');
		len++;
		n = -n;
	}
	if (n / 10)
		len += print_number(n / 10);
	putchar((n % 10) + '0');
	len++;
	return (len);
}
/**
 * _printf - Prints a formatted string.
 * @format: The format string to print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					len += print_string(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					len += print_number(va_arg(args, int));
					break;
				default:
					putchar('%');
					putchar(*format);
					len += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
