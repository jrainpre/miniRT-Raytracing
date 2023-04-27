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

t_color	color_mult(t_color color, float_t factor)
{
	t_color	prod;

	prod.r = color.r * factor;
	prod.g = color.g * factor;
	prod.b = color.b * factor;
	prod.a = color.a;
	return (prod);
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

t_color	color_add(t_color color1, t_color color2)
{
	t_color	sum;

	sum.r = color1.r + color2.r;
	sum.g = color1.g + color2.g;
	sum.b = color1.b + color2.b;
	sum.a = color1.a + color2.a;
	return (sum);
}

t_color	color_mult_color(t_color color1, t_color color2)
{
	t_color	prod;

	prod.r = color1.r * color2.r;
	prod.g = color1.g * color2.g;
	prod.b = color1.b * color2.b;
	prod.a = color1.a * color2.a;
	return (prod);
}

t_color	color_add_factor(t_color color, float_t factor)
{
	t_color	sum;

	sum.r = color.r + factor;
	sum.g = color.g + factor;
	sum.b = color.b + factor;
	sum.a = color.a + factor;
	return (sum);
}

t_color	mix_light(t_color act_color, t_color obj_color, t_color light_color,
		float_t ratio)
{
	t_color	mix;

	mix = color_mix(obj_color, light_color);
	mix = color_mult(mix, ratio);
	mix = color_add(act_color, mix);
	mix = color_clamp(mix, 0.0f, 1.0f);
	return (mix);
}

float_t get_reflect_factor_from_str(char *str)
{
	float_t	reflect_factor;

	if (str == NULL)
		return (0);
	reflect_factor = ft_atof(str);
	if (reflect_factor < 0 || reflect_factor > 1)
		return (0);
	return (reflect_factor);
}
