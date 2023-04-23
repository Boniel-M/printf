#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - prints a formatted output
 * @format: the format string
 *
 * Return: number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
#include <stdio.h>
/**
 * main - Entry Point
 *
 * Return: 0 always
 */
int main(void)
{
	int count;

	count = _printf("Hello, %s! The answer is %d.\n", "world", 42);
	printf("Characters printed: %d\n", count);
	return 0;
}
