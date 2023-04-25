#include "main.h"

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr = NULL;

	if (ptr == NULL)
	{
		new_ptr = malloc(size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	free(ptr);
	return (new_ptr);
}
