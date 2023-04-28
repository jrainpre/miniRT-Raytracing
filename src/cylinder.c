#include "miniRT.h"

int	add_cylinder(t_lst_ref *objects, char *line)
{
	t_cylinder	*cylinder;
	char		**parameters;
	char		**orig;
	char		**axis;
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
	axis = ft_split(parameters[2], ',');
	if (axis == NULL)
	{
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		return (-1);
	}
	color = ft_split(parameters[5], ',');
	if (color == NULL)
	{
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		axis = free_arr_null(axis);
		return (-1);
	}
	cylinder = malloc_or_print_error(sizeof (t_cylinder));
	if (cylinder == NULL)
		return (-1);
	cylinder->orig = get_vec_from_str_arr(orig);
	cylinder->axis = get_vec_from_str_arr(axis);
	if (!is_normalized(cylinder->axis))
	{
		cylinder = free_null(cylinder);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		axis = free_arr_null(axis);
		color = free_arr_null(color);
		return (-1);
	}
	cylinder->radius = ft_atof(parameters[3]) / 2;
	cylinder->height = ft_atof(parameters[4]);
	cylinder->color = get_color_from_str_arr(color);
	if (!is_valid_color(cylinder->color))
	{
		cylinder = free_null(cylinder);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		axis = free_arr_null(axis);
		color = free_arr_null(color);
		return (-1);
	}
	cylinder->reflect_factor = get_reflect_factor_from_str(parameters[6]);
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	axis = free_arr_null(axis);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(cylinder), objects);
	ft_lstlast(objects->head)->type = CYLINDER;
	ft_lstlast(objects->head)->is_slected = 0;
	print_object(cylinder, CYLINDER);
	return (0);
}
