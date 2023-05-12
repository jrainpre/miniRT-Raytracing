#include "miniRT.h"

int	color_conversion(t_color color)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = color.r * 255.0f;
	g = color.g * 255.0f;
	b = color.b * 255.0f;
	a = (1 - color.a) * 255.0f;
	return (a << 24 | r << 16 | g << 8 | b);
}

t_color	get_color_from_str_arr(char **str)
{
	t_color	color;

	color.r = ft_atoi(str[0]) / 255.0f;
	color.g = ft_atoi(str[1]) / 255.0f;
	color.b = ft_atoi(str[2]) / 255.0f;
	color.a = 1;
	return (color);
}

t_color	color_mix(t_color obj_color, t_color light_color)
{
	t_color	mix;

	mix.r = (obj_color.r + light_color.r) / 2;
	mix.g = (obj_color.g + light_color.g) / 2;
	mix.b = (obj_color.b + light_color.b) / 2;
	return (mix);
}



t_color	color_clamp(t_color color, float_t min, float_t max)
{
	t_color	clamped;

	clamped.r = clamp(color.r, min, max);
	clamped.g = clamp(color.g, min, max);
	clamped.b = clamp(color.b, min, max);
	clamped.a = clamp(color.a, min, max);
	return (clamped);
}
