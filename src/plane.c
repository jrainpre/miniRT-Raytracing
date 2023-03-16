#include "miniRT.h"

int	add_plane(t_lst_ref *objects, char *line)
{
	t_plane	*plane;
	char	**parameters;
	char	**point;
	char	**normal_vec;
	char	**color;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (-1);
	point = ft_split(parameters[1], ',');
	if (point == NULL)
	{
		parameters = free_arr_null(parameters);
		return (-1);
	}
	normal_vec = ft_split(parameters[2], ',');
	if (normal_vec == NULL)
	{
		parameters = free_arr_null(parameters);
		point = free_arr_null(point);
		return (-1);
	}
	color = ft_split(parameters[3], ',');
	if (color == NULL)
	{
		parameters = free_arr_null(parameters);
		point = free_arr_null(point);
		normal_vec = free_arr_null(normal_vec);
		return (-1);
	}
	plane = malloc_or_print_error(sizeof (t_plane));
	if (plane == NULL)
		return (-1);
	plane->point = get_vec_from_str_arr(point);
	plane->normal_vec = get_vec_from_str_arr(normal_vec);
	if (!is_normalized(plane->normal_vec))
	{
		plane = free_null(plane);
		parameters = free_arr_null(parameters);
		point = free_arr_null(point);
		normal_vec = free_arr_null(normal_vec);
		color = free_arr_null(color);
		return (-1);
	}
	plane->color = get_color_from_str_arr(color);
	if (!is_valid_color(plane->color))
	{
		plane = free_null(plane);
		parameters = free_arr_null(parameters);
		point = free_arr_null(point);
		normal_vec = free_arr_null(normal_vec);
		color = free_arr_null(color);
		return (-1);
	}
	parameters = free_arr_null(parameters);
	point = free_arr_null(point);
	normal_vec = free_arr_null(normal_vec);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(plane), objects);
	ft_lstlast(objects->head)->type = PLANE;
	print_object(plane, PLANE);
	return (0);
}
