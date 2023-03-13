#include "miniRT.h"

int	add_sphere(t_lst_ref *objects, char *line)
{
	t_sphere	*sphere;
	char		**parameters;
	char		**orig;
	char		**color;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (-1);
	orig = ft_split(parameters[1], ',');
	if (orig == NULL)
	{
		parameters = free_arr_null(parameters);
		return (-1);
	}
	color = ft_split(parameters[3], ',');
	if (color == NULL)
	{
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		return (-1);
	}
	sphere = malloc_or_print_error(sizeof (t_sphere));
	if (sphere == NULL)
		return (-1);
	sphere->orig = (t_pt3){ft_atof(orig[0]), ft_atof(orig[1]), ft_atof(orig[2])};
	sphere->radius = ft_atof(parameters[2]) / 2;
	sphere->color = get_color_from_str_arr(color);
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
	return (0);
}
