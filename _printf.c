#include "main.h"
#include <unistd.h>
#include <stdarg.h>

void print_buffer(char buffer[], int *index_buffer);

/**
* _printf - prints on the screen
* @format: string format.
*
* Return: the size of the string format.
*/

int _printf(const char *format, ...)
{
	int j, num_chars = 0;
	va_list args;

	va_start(args, *format)

	while (format && format[j])
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 'c')
			{
				char c = va_arg(args, int);

				print_buffer(c);
				num_chars++;
			}
			else if (format[j] == 's')
			{
				char c = va_arg(args, char *)

				while (*s)
				{
					print_buffer(*s);
					s++;
					num_chars++;
				}
			}
			else if (format[j] == '%')
			{
				print_buffer('%');
				num_chars++;
			}
		}
		else
		{
			print_buffer(format[i]);
			num_chars++;
		}
		j++;

	}

	va_end(args);

	return (num_chars);

}

/**
* print_buffer - prints on the buffer
* @buffer: the format string
* @index_buffer: size on char in the buffer
*
* Return: void
*/

void print_buffer(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
	{
		write(1, &buffer[0], *index_buffer);
	}

	*index_buffer = 0;
}
