#include <stdlib.h>
#include "main.h"

/**
 * get_number_length - gets the length of a number
 * @n: the number to get the length of
 * Return: the length of the number
 */
int get_number_length(int n)
{
		int i = 0;

		if (n == 0)
			return (1);
		if (n < 0)
		{
			n *= -1;
			i++;
		}
		while (n)
		{
			n /= 10;
			i++;
		}
		return (i);
}

/**
 * reverse_string - reverses a string
 * @str: string to reverse
 * Return: pointer to the reversed string
 */
char *reverse_string(char *str)
{
	int start = 0, end = _strlen(str) - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}

	return (str);
}

/**
 * _itoa - converts an integer to a string
 * @value: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_itoa(ssize_t value, char *base)
{
	char *result = malloc(get_number_length(value) + 1);
	ssize_t quotient = ABS(value), i = 0;
	int base_len = _strlen(base);

	if (base_len < 2 || base_len > 16)
		return (NULL);

	do {
		result[i++] = base[quotient % base_len];
		quotient /= base_len;
	} while (quotient);

	if (value < 0 && base_len == 10)
		result[i++] = '-';

	result[i] = '\0';
	return (reverse_string(result));
}

