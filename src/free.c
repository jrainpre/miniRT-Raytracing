#include "miniRT.h"

void	*free_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
