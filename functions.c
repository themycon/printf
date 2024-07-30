#include "main.h"

/**
* print_binary - Converts an unsigned int to binary and stores it in a buffer
* @buffer: Buffer array to store the binary representation
* @index_buffer: Current index in the buffer
* @n: The unsigned int to be converted
* @num_chars: Pointer to the number of characters that are printed
*/
void print_binary(char buffer[], int *index_buffer, unsigned int n,
		  int *num_chars)
{
	char str[32];
	int i = 0;

	if (n == 0)
	{
		buffer[(*index_buffer)++] = '0';
		(*num_chars)++;
	}
	else
	{
		while (n > 0)
		{
			str[i++] = (n % 2) + '0';
			n /= 2;
		}

		while (--i >= 0)
		{
			buffer[(*index_buffer)++] = str[i];
			(*num_chars)++;
			if (*index_buffer >= BUFFER_SIZE)
			{
				print_buffer(buffer, index_buffer);
			}
		}
	}
}

/**
* print_char - Handles the 'c' specifier
* @buffer: Buffer array to store characters
* @index_buffer: Current index in the buffer
* @c: The character to print
* @num_chars: Pointer to the number of characters printed
*/
void print_char(char buffer[], int *index_buffer, char c, int *num_chars)
{
	buffer[(*index_buffer)++] = c;
	(*num_chars)++;
	if (*index_buffer >= BUFFER_SIZE)
	{
		print_buffer(buffer, index_buffer);
	}
}

/**
* print_string - Handles the 's' specifier
* @buffer: Buffer array to store characters
* @index_buffer: Current index in the buffer
* @s: The string to print
* @num_chars: Pointer to the number of characters printed
*/
void print_string(char buffer[], int *index_buffer, char *s, int *num_chars)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		buffer[(*index_buffer)++] = *s++;
		(*num_chars)++;
		if (*index_buffer >= BUFFER_SIZE)
		{
			print_buffer(buffer, index_buffer);
		}
	}
}

/**
* print_unsigned_int - converts an unsigned int to string
* @buffer: Buffer array to store the string representation
* @index_buffer: Current index in the buffer
* @n: The unsigned int to convert
* @num_chars: Pointer to the number of characters printed
*/

void print_unsigned_int(char buffer[], int *index_buffer, unsigned int n,
			int *num_chars)
{
	char str[10];
	int i = 0, j;

	if (n == 0)
	{
		str[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			str[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[(*index_buffer)++] = str[j];
		(*num_chars)++;

		if (*index_buffer >= BUFFER_SIZE)
		{
			print_buffer(buffer, index_buffer);
		}
	}
}

/**
* print_octal - Converts an unsigned int to octal
* @buffer: Buffer array to store the octal representation
* @index_buffer: Current index in the buffer
* @n: The unsigned int to convert
* @num_chars: Pointer to the number of characters printed
*/

void print_octal(char buffer[], int *index_buffer, unsigned int n,
		 int *num_chars)
{
	char str[11];
	int i = 0, j;

	if (n == 0)
	{
		str[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			str[i++] = (n % 8) + '0';
			n /= 8;
		}
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[(*index_buffer)++] = str[j];
		(*num_chars)++;

		if (*index_buffer >= BUFFER_SIZE)
		{
			print_buffer(buffer, index_buffer);
		}
	}
}
