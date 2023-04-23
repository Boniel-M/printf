#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function that produces an output according format
 * @format: string to format.
 * Return: number of char printed
 */
int _putchar(char c)
{
	return (putchar(c));
}
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;
	char c;

	va_start(args, format);

	while ((c = *format++))
	{
		if (c == '%')
		{
			c = *format++;
			if (c == 'c')
			{
				count += putchar(va_arg(args, int));
			}
			else if (c == 's')
			{
				char *str = va_arg(args, char *);
				
				while (*str)
				{
					count += putchar(*str++);
				}
			}
			else if (c == '%')
			{
				count += putchar('%');
			}
			else
			{
				count += putchar('%');
				count += putchar(c);
			}
		}
		else
		{
			count += putchar(c);
		}
	}
	va_end(args);
	return count;
}
