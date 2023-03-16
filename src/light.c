#include "miniRT.h"

t_light	*init_light(char *line)
{
	t_light	*light;
	char	**parameters;
	char	**orig;
	char	**color;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (NULL);
	orig = ft_split(parameters[1], ',');
	if (orig == NULL)
	{
		parameters = free_arr_null(parameters);
		return (NULL);
	}
	color = ft_split(parameters[3], ',');
	if (color == NULL)
	{
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		return (NULL);
	}
	light = malloc_or_print_error(sizeof (t_light));
	if (light == NULL)
		return (NULL);
	light->orig = get_vec_from_str_arr(orig);
	light->ratio = ft_atof(parameters[2]);
	if (!is_valid_ratio(light->ratio))
	{
		light = free_null(light);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		color = free_arr_null(color);
		return (NULL);
	}
	light->color = get_color_from_str_arr(color);
	if (!is_valid_color(light->color))
	{
		light = free_null(light);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		color = free_arr_null(color);
		return (NULL);
	}
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
	return (light);
}

void	translate_light(t_light *light, t_vec3 vec)
{
	light->orig = vec_add(light->orig, vec);
}
