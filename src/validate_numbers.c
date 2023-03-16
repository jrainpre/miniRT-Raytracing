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

int	is_valid_color(t_color color)
{
	if (color.r < 0 || 1 < color.r)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Red expected to be between 0 and 255\n", STDERR_FILENO);
		return (0);
	}
	if (color.g < 0 || 1 < color.g)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Green expected to be between 0 and 255\n", STDERR_FILENO);
		return (0);
	}
	if (color.b < 0 || 1 < color.b)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Blue expected to be between 0 and 255\n", STDERR_FILENO);
		return (0);
	}
	if (color.a < 0 || 1 < color.a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Alpha expected to be between 0 and 255\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

int	is_normalized(t_vec3 vec)
{
	if (fabsf(vec_length(vec) - 1.0f) > FLT_EPSILON)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Vector expected to be normalized\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
