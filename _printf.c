#include "main.h"
#include <unistd.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

void print_buffer(char buffer[], int *index_buffer);
void print_int(char buffer[], int *index_buffer, int n, int *num_chars,
	       int plus_flag, int space_flag);

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
	int plus_flag = 0, space_flag = 0, hash_flag = 0;
	int length_modifier = 0;

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

			while (format[j] == '+' || format[j] == ' ' || format[j] == '#')
			{
				if (format[j] == '+')
					plus_flag = 1;
				else if (format[j] == ' ')
					space_flag = 1;
				else if (format[j] == '#')
					hash_flag = 1;
				j++;
			}
			if (format[j] == 'h')
			{
				length_modifier = 1;
				j++;
				if (format[j] == 'h')
				{
					length_modifier = 2;
					j++;
				}
			}
			else if (format[j] == 'l')
			{
				length_modifier = 3;
				j++;
			}

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
				if (length_modifier == 1)
					print_int(buffer, &index_buffer, (short)va_arg(args, int),
						  &num_chars, plus_flag, space_flag);
				else if (length_modifier == 2)
					print_int(buffer, &index_buffer, (char)va_arg(args, int),
						  &num_chars, plus_flag, space_flag);
				else if (length_modifier == 3)
					print_int(buffer, &index_buffer, (long)va_arg(args, long),
						  &num_chars, plus_flag, space_flag);
				else
					print_int(buffer, &index_buffer, va_arg(args, int),
						  &num_chars, plus_flag, space_flag);
			}
			else if (format[j] == 'b')
			{
				unsigned int n = va_arg(args, unsigned int);

				print_binary(buffer, &index_buffer, n, &num_chars);
			}
			else if (format[j] == 'u')
			{
				if (length_modifier == 1)
					print_unsigned_int(buffer, &index_buffer,
							   (unsigned short)va_arg(args, unsigned int), &num_chars);
				else if (length_modifier == 2)
					print_unsigned_int(buffer, &index_buffer,
							   (unsigned char)va_arg(args, unsigned int), &num_chars);
				else if (length_modifier == 3)
					print_unsigned_int(buffer, &index_buffer,
							   va_arg(args, unsigned long), &num_chars);
				else
					print_unsigned_int(buffer, &index_buffer,
							   va_arg(args, unsigned int), &num_chars);
			}
			else if (format[j] == 'o')
			{
				if (length_modifier == 1)
					print_octal(buffer, &index_buffer, (unsigned short)va_arg(args,
						    unsigned int), &num_chars, hash_flag);
				else if (length_modifier == 2)
					print_octal(buffer, &index_buffer, (unsigned char)va_arg(args,
						    unsigned int), &num_chars, hash_flag);
				else if (length_modifier == 3)
					print_octal(buffer, &index_buffer, va_arg(args,
						    unsigned long), &num_chars, hash_flag);
				else
					print_octal(buffer, &index_buffer, va_arg(args,
						    unsigned int), &num_chars, hash_flag);
			}
			else if (format[j] == 'x')
			{
				if (length_modifier == 1)
					print_hex(buffer, &index_buffer, (unsigned short)va_arg(args,
						  unsigned int), &num_chars, 0, hash_flag);
				else if (length_modifier == 2)
					print_hex(buffer, &index_buffer, (unsigned char)va_arg(args,
						  unsigned int), &num_chars, 0, hash_flag);
				else if (length_modifier == 3)
					print_hex(buffer, &index_buffer, va_arg(args,
						  unsigned long), &num_chars, 0, hash_flag);
				else
					print_hex(buffer, &index_buffer, va_arg(args,
						  unsigned int), &num_chars, 0, hash_flag);
			}
			else if (format[j] == 'X')
			{
				if (length_modifier == 1)
					print_hex(buffer, &index_buffer, (unsigned short)va_arg(args,
						  unsigned int), &num_chars, 1, hash_flag);
				else if (length_modifier == 2)
					print_hex(buffer, &index_buffer, (unsigned char)va_arg(args,
						  unsigned int), &num_chars, 1, hash_flag);
				else if (length_modifier == 3)
					print_hex(buffer, &index_buffer, va_arg(args,
						  unsigned long), &num_chars, 1, hash_flag);
				else
					print_hex(buffer, &index_buffer, va_arg(args,
						  unsigned int), &num_chars, 1, hash_flag);
			}
			else if (format[j] == 'S')
			{
				char *str = va_arg(args, char *);

				print_special_string(buffer, &index_buffer, str, &num_chars);
			}
			else if (format[j] == 'p')
			{
				void *ptr = va_arg(args, void *);

				print_pointer(buffer, &index_buffer, ptr, &num_chars);
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
* @plus_flag: a plus flag
* @space_flag: a space flag
*/

void print_int(char buffer[], int *index_buffer, int n, int *num_chars,
	       int plus_flag, int space_flag)
{
	char str[12];
	int k;

	int_to_str(n, str);

	if (n >= 0)
	{
		if (plus_flag)
			buffer[(*index_buffer)++] = '+';
		else if (space_flag)
			buffer[(*index_buffer)++] = ' ';
		(*num_chars)++;
	}

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
