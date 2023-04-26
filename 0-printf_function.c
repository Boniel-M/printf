#include <stdarg.h>
#include <stdio.h>

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
    return len;
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
                case 'c':
                    putchar(va_arg(args, int));
                    len++;
                    break;
                case 's':
                    len += print_string(va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    len++;
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
    return len;
}
