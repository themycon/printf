#include "main.h"

/**
* print_hex - Converts an unsigned int to hexadecimal
* @buffer: Buffer array to store the hexadecimal representation
* @index_buffer: Current index in the buffer
* @n: The unsigned int to convert
* @num_chars: Pointer to the number of characters printed
* @uppercase: Flag to indicate whether the output should be in uppercase
*/

void print_hex(char buffer[], int *index_buffer, unsigned int n,
	       int *num_chars, int uppercase)
{
	char str[20];
	int i = 0;
	char base = uppercase ? 'A' : 'a';

	if (n == 0)
	{
		buffer[(*index_buffer)++] = '0';
		(*num_chars)++;
	}
	else
	{
		while (n > 0)
		{
			int digit = n % 16;

			if (digit < 10)
				str[i++] = digit + '0';
			else
				str[i++] = digit - 10 + base;
			n /= 16;
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
* print_special_string - prints special strings
* @buffer: buffer to hold the string before printing
* @index_buffer: position of the buffer
* @str: the string to be printed
* @num_chars: pointer to the number of characters
*/

void print_special_string(char buffer[], int *index_buffer, const char *str,
			  int *num_chars)
{
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			buffer[(*index_buffer)++] = '\\';
			buffer[(*index_buffer)++] = 'x';
			*num_chars += 2;

			if (*index_buffer >= BUFFER_SIZE - 2)
			{
				print_buffer(buffer, index_buffer);
			}

			printing_hex_for_special_string(buffer, index_buffer,
							(unsigned int)*str, num_chars, 1);
		}
		else
		{
			buffer[(*index_buffer)++] = *str;
			(*num_chars)++;
		}

		if (*index_buffer >= BUFFER_SIZE)
		{
			print_buffer(buffer, index_buffer);
		}

		str++;
	}
}

/**
* printing_hex_for_special_string - prints hexadecimal for special strings
* @buffer: buffer to hold the string before printing
* @index_buffer: position of the buffer
* @n: the position of the char in ascii
* @num_chars: pointer to the number of characters
* @uppercase: bases the hexadecimal in upper or lower case
*/
void printing_hex_for_special_string(char buffer[], int *index_buffer,
				     unsigned int n, int *num_chars, int uppercase)
{
	char str[3];
	int i = 0;
	char base = uppercase ? 'A' : 'a';

	if (n == 0)
	{
		str[i++] = '0';
		str[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			int digit = n % 16;

			if (digit < 10)
				str[i++] = digit + '0';
			else
				str[i++] = digit - 10 + base;
			n /= 16;
		}

		while (i < 2)
			str[i++] = '0';
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
