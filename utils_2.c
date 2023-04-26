#include <unistd.h>
#include <stdlib.h>

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

/**
 * free_resources - frees all resources
 * @line: line to free
 * @tokens: tokens to free
 * Return: void
 */
void free_resources(char **line, char ***tokens)
{
	int i;

	for (i = 0; (*tokens)[i]; i++)
		free((*tokens)[i]);
	free(*tokens);

	free(*line);
	*line = NULL;
	*tokens = NULL;
}

/**
 * free_line - free the line
 * @line: line to be freed
 */
void free_line(char **line)
{
	free(*line);
	*line = NULL;
}
