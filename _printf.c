#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function that produces an output according format
 * @format: string to format.
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	int counter = 0;
	char c;
	char *s;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = (char) va_arg(args, int);
				putchar(c);
				counter++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				puts(s);
				counter += strlen(s);
			}
			else if (*format == '%')
			{
				putchar('%');
				counter++;
			}
			else
			{
				putchar(*format);
				counter++;
			}
			format++;
		}
	}
	va_end(args);
	return (counter);
}
