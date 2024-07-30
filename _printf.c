#include "main.h"
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

void print_buffer(char buffer[], int *index_buffer);
void print_int(char buffer[], int *index_buffer, int n, int *num_chars);
void int_to_str(int n, char str[]);

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
			if (format[j] == '\0')
				break;

			if (format[j] == 'c')
			{
				char c = va_arg(args, int);

				print_char(buffer, &index_buffer, c, &num_chars);
			}
			else if (format[j] == 's')
			{
				char *s = va_arg(args, char *);

				print_string(buffer, &index_buffer, s, &num_chars);
			}
			else if (format[j] == '%')
			{
				buffer[index_buffer++] = '%';
				num_chars++;
			}
			else if (format[j] == 'd' || format[j] == 'i')
			{
				int n = va_arg(args, int);

				print_int(buffer, &index_buffer, n, &num_chars);
			}
			else if (format[j] == 'b')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_binary(buffer, &index_buffer, n, &num_chars);
			}
			else if (format[j] == 'u')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_unsigned_int(buffer, &index_buffer, n, &num_chars);
			}
			else if (format[j] == 'o')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_octal(buffer, &index_buffer, n, &num_chars);
			}
			else if (format[j] == 'x')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_hex(buffer, &index_buffer, n, &num_chars, 0);
			}
			else if (format[j] == 'X')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_hex(buffer, &index_buffer, n, &num_chars, 1);
			}
			else
			{
				buffer[index_buffer++] = '%';
				buffer[index_buffer++] = format[j];
				num_chars += 2;
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
* print_int - prints what is in the d and i specifiers
* @buffer: buffer array
* @index_buffer: is the current index of the buffer
* @n: the integer
* @num_chars: pointer to the number of characters
*/

void print_int(char buffer[], int *index_buffer, int n, int *num_chars)
{
	char str[12];
	int k;

	int_to_str(n, str);

	for (k = 0; str[k]; k++)
	{
		buffer[*index_buffer] = str[k];
		(*index_buffer)++;
		(*num_chars)++;
		if (*index_buffer >= BUFFER_SIZE)
		{
			print_buffer(buffer, index_buffer);
		}
	}
}

/**
* int_to_str - converts intergers to a string
* @n: the integer value
* @str: buffer stores the new string converted from integer
*/

void int_to_str(int n, char str[])
{
	int i = 0, j = 0;
	int negative_n = 0;
	int temp;

	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}
	if (n < 0)
	{
		negative_n = 1;
		if (n == -2147483648)
		{
			n = 2147483647;
			str[i++] = (n % 10) + 1 + '0';
			n /= 10;
		}
		else
		{
			n = -n;
		}
	}
	while (n != 0)
	{
		temp = n % 10;
		str[i++] = temp + '0';
		n = n / 10;
	}
	if (negative_n)
	{
		str[i++] = '-';
	}
	str[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		char c = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = c;
	}
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
