#include "miniRT.h"

int	is_valid_ratio(float_t ratio)
{
	if (ratio < 0 || 1 < ratio)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Ratio expected to be between 0 and 1\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
