#include "main.h"
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024


void print_buffer(char buffer[], int *index_buffer);

/**
* _printf - prints on the screen
* @format: string format.
*
* Return: the size of the string format.
*/

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFFER_SIZE];
	int index_buffer = 0;
	int j = 0;
	int num_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[j])
	{
		if (format[j] == '%')
		{
			print_buffer(buffer, &index_buffer);
			j++;
			if (format[j] == 'c')
			{
				char c = va_arg(args, int);

				buffer[index_buffer++] = c;
				num_chars++;
			}
			else if (format[j] == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
				{
					s = "(null)";
				}
				while (*s)
				{
					buffer[index_buffer++] = *s++;
					num_chars++;
				}
			}
			else if (format[j] == '%')
			{
				buffer[index_buffer++] = '%';
				num_chars++;
			}

			if (index_buffer >= BUFFER_SIZE)
			{
				print_buffer(buffer, &index_buffer);
			}
		}
		else
		{
			buffer[index_buffer++] = format[j];
			num_chars++;

			if (index_buffer >= BUFFER_SIZE)
			{
				print_buffer(buffer, &index_buffer);
			}
		}
		j++;

	}
	print_buffer(buffer, &index_buffer);

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
