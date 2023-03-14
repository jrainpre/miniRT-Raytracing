#include "miniRT.h"

t_ambient_light	*init_ambient_light(char *line)
{
	t_ambient_light	*ambient_light;
	char			**parameters;
	char			**color;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (NULL);
	color = ft_split(parameters[2], ',');
	if (color == NULL)
	{
		parameters = free_arr_null(parameters);
		return (NULL);
	}
	ambient_light = malloc_or_print_error(sizeof (t_ambient_light));
	if (ambient_light == NULL)
		return (NULL);
	ambient_light->ratio = ft_atof(parameters[1]);
	ambient_light->color = get_color_from_str_arr(color);
	parameters = free_arr_null(parameters);
	color = free_arr_null(color);
	return (ambient_light);
}
