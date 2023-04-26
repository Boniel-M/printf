#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
            format++;

            switch (*format)
            {
                case 'c':
                {
                    char ch = (char) va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        putchar(*str++);
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
            }
        }
        else
        {
            putchar(c);
            count++;
        }
    }

    va_end(args);
    return count;
}
