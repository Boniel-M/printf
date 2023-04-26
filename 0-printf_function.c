#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 *
 * @format: a character string containing zero or more directives
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 *
 * This function prints output according to a format string that may contain zero
 * or more directives. The format string is composed of zero or more characters,
 * which may include conversion specifiers beginning with % character.
 * Supported conversion specifiers are %c, %s, and %%.
 *
 * For %c, the function prints a single character passed as an integer argument.
 * For %s, the function prints a string argument.
 * For %%, the function prints a literal % character.
 *
 * @format may also contain other characters that are printed verbatim.
 * The function returns the total number of characters printed (excluding the
 * null byte used to end output to strings).
 *
 * The function does not handle field width, precision, or length modifiers.
 * It uses variable arguments, as indicated by the use of stdarg.h and the va_
 * functions.
 */
int _printf(const char *format, ...)
{
    va_list args;

    int count = 0;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char*));
                    break;
                case '%':
                    count += printf("%%");
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
