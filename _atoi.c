
/**
 * _isspace - checks if a character is a whitespace character
 * @c: the character to check
 * Return: 1 if the character is a whitespace character, 0 otherwise
 */
static int	_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 * Return: integer value of string
 */
int	_atoi(const char *str)
{
	int	res = 0, sign = 1, i = 0;

	/* skip whitespace */
	while (_isspace(str[i]))
		i++;

	/* check for sign */
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	/* convert to integer */
	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
		res = (res * 10) + (str[i] - '0');

	return (res * sign);
}
