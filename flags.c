#include <stdarg.h>
#include <stdio.h>
#include <main.h>
/**
 * _printf - Prints a formatted string to the standard output stream
 * @format: A pointer to a string to be printed
 *          to the standard output stream
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	
	int printed_chars = 0;
	
	va_start(args, format);
	
	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					printed_chars += printf("%d", va_arg(args, int));
					break;
				default:
					putchar(*format);
					printed_chars++;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
