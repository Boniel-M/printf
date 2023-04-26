#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * print_number - Prints an integer.
 * @n: The integer to print.
 */
void print_number(int n)
{
    unsigned int num;

    if (n < 0)
    {
        putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
    {
        print_number(num / 10);
    }

    putchar((num % 10) + '0');
}

/**
 * _printf - Prints a formatted string.
 * @format: The format string to print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int len = 0;
    va_list args;
    const char *p;

    va_start(args, format);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;

            switch (*p)
            {
                case 'd':
                case 'i':
                    print_number(va_arg(args, int));
                    len++;
                    break;
                default:
                    putchar('%');
                    putchar(*p);
                    len += 2;
                    break;
            }
        }
        else
        {
            putchar(*p);
            len++;
        }
    }

    va_end(args);

    return len;
}
