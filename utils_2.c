#include <unistd.h>

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to find
 * Return: pointer to first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
	}

	if (s[i] == c)
		return (s + i);
	else
		return (0);
}

/**
 * _memset - fills memory with a constant byte
 * @s: memory area to fill
 * @b: constant byte
 * @n: number of bytes to fill
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
		s[i++] = b;

	return (s);
}

/**
 * _abs - computes the absolute value of an integer
 * @n: integer to compute
 * Return: absolute value of n
*/
ssize_t _abs(ssize_t n)
{
	return (n < 0 ? -n : n);
}
