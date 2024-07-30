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
