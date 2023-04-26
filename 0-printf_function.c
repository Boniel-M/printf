#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "common_functions.h"
#include "main.h"
/**
 * _printf - Custom implementation of printf function
 *
 * @format: Format string
 *
 * @...: Variable argument list
 * Return: Number of characters printed
*/
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
			char specifier = *format++;

			switch (specifier)
			{
				case 'c':
					{
						char arg_c = (char) va_arg(args, int);

						putchar(arg_c);
						count++;
						break;
					}
				case 's':
					{
						char *arg_str = va_arg(args, char *);
						
						if (arg_str == NULL)
						{
							arg_str = "(null)";
						}
						while (*arg_str)
						{
							putchar(*arg_str++);
							count++;
						}
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				default:
					{
						putchar('%');
						putchar(specifier);
						count += 2;
						break;
					}
			}
		}
		else
		{
			putchar(c);
			count++;
		}
	}
	va_end(args);
	return (count);
}
