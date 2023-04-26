#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * The `_printf()` function formats and prints data to the standard output stream
 *
 * @param format - The format string that contains zero or more directives
 * @param ... - The optional arguments to be formatted
 * @return The number of characters printed (excluding the null byte used to end output to strings)
 *
 * The format string can contain conversion specifiers:
 * - %c - Character
 * - %s - String
 * - %% - Percent character
 *
 * Unsupported conversion specifiers will result in undefined behavior.
 * Field width and precision are not supported in this implementation.
 */
int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    /* unsupported conversion specifier */
                    va_end(args);
                    return (-1);
                }
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return (count);
}

int main() {
    int num_chars;
    num_chars = _printf("Testing _printf() function in C\n");
    num_chars = _printf("Character: %c\n", 'a');
    num_chars = _printf("String: %s\n", "Hello, world!");
    num_chars = _printf("Percent sign: %%\n");
    num_chars = _printf("The number of characters printed is: %d\n", 42);
    num_chars = _printf("The total number of characters printed is: %d\n", num_chars);
    return (0);
}
