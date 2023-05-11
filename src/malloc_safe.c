#include "miniRT.h"

void	*malloc_or_print_error(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}

void	*calloc_or_print_error(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		ft_putstr_fd("calloc error\n", STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}
