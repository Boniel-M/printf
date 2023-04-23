#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i = 0, j = 0, len = 0;
        char *str;

        va_start(args, format);

        while (format[i] != '\0')
        {
                if (format[i] == '%')
                {
                        i++;
                        switch (format[i])
                        {
                                case 'c':
                                        len += write(1, (char)va_arg(args, int), 1);
                                        break;
                                case 's':
                                        str = va_arg(args, char *);
                                        while (str[j] != '\0')
                                        {
                                                len += write(1, &str[j], 1);
                                                j++;
                                        }
                                        break;
                                case '%':
                                        len += write(1, "%", 1);
                                        break;
                                default:
                                        len += write(1, "%", 1);
                                        len += write(1, &format[i], 1);
                                        break;
                        }
                }
                else
                {
                        len += write(1, &format[i], 1);
                }
                i++;
        }

        va_end(args);

        return len;
}

int main(void)
{
        _printf("Hello, %s! %c %%%s\n", "world", '!', "It works!");

        return (0);
}

