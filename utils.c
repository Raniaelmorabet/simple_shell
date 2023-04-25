#include <stdlib.h>

char *_strdup(char *str)
{
	char *dup = NULL;
	int i = 0;

	if (!str)
		return (NULL);

	while (str[i])
		i++;

	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);

	for (i = 0; str[i]; i++)
		dup[i] = str[i];

	dup[i] = '\0';

	return (dup);
}
