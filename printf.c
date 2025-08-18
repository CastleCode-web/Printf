#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
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
	int num;
	int i;
	char *str;
	char array[10];
	unsigned int unsigned_val;
	char binary[32];
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
			else if ((format[x] == 'd') || (format[x] == 'i'))
			{
				num = va_arg(args, int);
				/**
				* This casting takes care of INT_MIN.
				* Because the min value, (-2147483648)
				* can't fit into an int. You either
				* promote it as long or directly cast
				* to unsigned int to get the correct
				* binary representation
				*/
				unsigned_val = (num < 0) ? (unsigned int)(-((long)num)) : (unsigned int)num;
				if (num < 0)
				{
					_putchar('-');
					sum++;
				}
				else if (num == 0)
				{
					_putchar('0');
					sum++;
					continue;
				}
				i = 0;
				while (unsigned_val >= 10)
				{
					array[i] = unsigned_val % 10;
					unsigned_val = unsigned_val / 10;
					i++;
				}
				array[i] = unsigned_val;
				while (i >= 0)
				{
					_putchar(array[i] + '0');
					i--;
					sum++;
				}
			}
			else if (format[x] == 'b')
			{
				num = va_arg(args, unsigned int);
				if (num == 0)
				{
					x++;
					_putchar('0');
					sum++;
					continue;
				}
				i = 0;
				while (num > 2)
				{
					binary[i] = num % 2;
					num = num / 2;
					i++;
				}
				binary[i] = num;
				while (i >= 0)
				{
					_putchar(binary[i] + '0');
					i--;
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
