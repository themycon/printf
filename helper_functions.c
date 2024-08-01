#include "main.h"

/**
* int_to_str - Converts an integer to a string
* @n: The integer to be converted
* @str: The buffer to store the converted string
*/
void int_to_str(int n, char str[])
{
	int i = 0, j = 0, negative_n = 0, temp;

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
* unsigned_int_to_str - Converts an unsigned integer to a string
* @n: The unsigned integer to be converted
* @str: The buffer to store the converted string
*/
void unsigned_int_to_str(unsigned int n, char str[])
{
	int i = 0, j = 0, k;
	char temp;

	do {
		str[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	str[i] = '\0';

	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}


/**
* unsigned_int_to_octal_str - Converts an unsigned integer to an octal string
* @n: The unsigned integer to be converted
* @str: The buffer to store the converted octal string
*/
void unsigned_int_to_octal_str(unsigned long n, char str[])
{
	int i = 0, k;
	char temp;

	do {
		str[i++] = n % 8 + '0';
	} while ((n /= 8) > 0);

	str[i] = '\0';

	for (k = 0; k < i / 2; k++)
	{
		temp = str[k];
		str[k] = str[i - k - 1];
		str[i- k- 1] = temp;
	}
}

/**
* unsigned_int_to_hex_str - Converts an unsigned int to a hexadecimal string
* @n: The unsigned integer to be converted
* @str: The buffer to store the converted hexadecimal string
* @uppercase: Dertermines lower or uppercase hexadecimal string
*/
void unsigned_int_to_hex_str(unsigned long n, char str[], int uppercase)
{
	int i = 0, j = 0, k;
	char temp;
	char base = uppercase ? 'A' : 'a';

	do {
		int digit = n % 16;

		if (digit < 10)
			str[i++] = digit + '0';
		else
			str[i++] = digit - 10 + base;
	} while ((n /= 16) > 0);

	str[i] = '\0';

	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}
