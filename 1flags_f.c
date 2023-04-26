#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...) {
    int num_chars_printed = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
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
                        while (*str != '\0') {
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
                        printf("%d", num);
                        num_chars_printed++;
                        break;
                    }
            }
        } else {
            putchar(*format);
            num_chars_printed++;
        }
        format++;
    }

    va_end(args);

    return num_chars_printed;
}

