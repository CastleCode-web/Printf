#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints to standard output
 * @format - string to print
 *
 * Return: total sum of elements in the string and argument
 */
int _printf(const char *format, ...)
{
        int x = 0;
        int sum = 0;
        char y;
        int i;
        char *str;
        va_list args;

        /**
         * If no strings or argument is passed, return error
         */
        if (format == NULL)
                return (-1);
	va_start(args, format);
        while (format[x] != '\0')
        {
                if (format[x] == '%')
                {
			x++;
                        /**
                         * checks if the element/character after % is the
                         * terminating null byte (\0). The break ensures
                         * that a user passes a specifier after %
                         */
                        if (format[x] == '\0')
                                break;
                        if (format[x] == '%')
                        {
                                write(1, "%", 1);
                                sum++;
                        }
                        else if (format[x] == 'c')
                        {
                                /**
                                 * va_arg doesn't accept char as argument,
                                 * so it's casted
                                 */
                                y = (char)va_arg(args, int);
                                write(1, &y, 1);
                                sum++;
                        }
                        else if (format[x] == 's')
                        {
                                str = va_arg(args, char *);
                                /**
                                 * Checks if str points to NULL, and replaces
                                 * it with string literals (nill) instead.
                                 * Note that "NULL" in quotes is seen as string
                                 */
                                if (str == NULL)
                                        str = ("nill");
                                for (i = 0; str[i] != '\0'; i++)
                                {
                                        write(1, &str[i], 1);
                                        sum++;
                                }
                        }
                        else
                        {
                                _putchar('%');
                                write(1, &format[x], 1);
                                sum = sum + 2;
                        }
                }
                else
                {
                        write(1, &format[x], 1);
                        sum++;
                }
                x++;
        }
        va_end(args);
        return (sum);
}
