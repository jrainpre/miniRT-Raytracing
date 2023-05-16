#include "miniRT.h"

void	free_light(char **param, char **orig, char **color)
{
	param = free_arr_null(param);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
}

char	**handle_orig_and_color_light(char **orig, char **param)
{
	char	**color;

	if (orig == NULL)
	{
		param = free_arr_null(param);
		return (NULL);
	}
	color = ft_split(param[3], ',');
	if (color == NULL)
	{
		param = free_arr_null(param);
		orig = free_arr_null(orig);
		return (NULL);
	}
	return (color);
}

int	fill_light_data(t_light *light, char **orig, char **param, char **color)
{
	light->orig = get_vec_from_str_arr(orig);
	light->ratio = ft_atof(param[2]);
	if (!is_valid_ratio(light->ratio))
		return (0);
	light->color = get_color_from_str_arr(color);
	if (!is_valid_color(light->color))
		return (0);
	return (1);
}

t_light	*init_light(char *line)
{
	t_light	*light;
	char	**param;
	char	**orig;
	char	**color;

	param = ft_split(line, ' ');
	if (param == NULL)
		return (NULL);
	orig = ft_split(param[1], ',');
	color = handle_orig_and_color_light(orig, param);
	if (color == NULL)
		return (NULL);
	light = malloc_or_print_error(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	if (!fill_light_data(light, orig, param, color))
	{
		light = free_null(light);
		free_light(param, orig, color);
		return (NULL);
	}
	free_light(param, orig, color);
	return (light);
}

void	translate_light(t_light *light, t_vec3 vec)
{
	light->orig = vec_add(light->orig, vec);
}
