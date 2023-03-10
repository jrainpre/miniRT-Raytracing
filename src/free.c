#include "miniRT.h"

void	*free_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*free_arr_null(char **arr)
{
	int	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		arr[i] = free_null(arr[i]);
		i++;
	}
	arr = free_null(arr);
	return (NULL);
}
