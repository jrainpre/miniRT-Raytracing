#include "miniRT.h"

int	get_values_plane(char ***param, char ***point, char ***normal_vec,
		char ***color)
{
	*point = ft_split((*param)[1], ',');
	if (*point == NULL)
	{
		*param = free_arr_null(*param);
		return (-1);
	}
	*normal_vec = ft_split((*param)[2], ',');
	if (*normal_vec == NULL)
	{
		*param = free_arr_null(*param);
		*point = free_arr_null(*point);
		return (-1);
	}
	*color = ft_split((*param)[3], ',');
	if (*color == NULL)
	{
		*param = free_arr_null(*param);
		*point = free_arr_null(*point);
		*normal_vec = free_arr_null(*normal_vec);
		return (-1);
	}
	return (0);
}

int	assign_values_plane(t_plane *plane, char **point, char **normal_vec,
		char **color)
{
	plane->point = get_vec_from_str_arr(point);
	plane->normal_vec = get_vec_from_str_arr(normal_vec);
	if (!is_normalized(plane->normal_vec))
		return (-1);
	plane->color = get_color_from_str_arr(color);
	if (!is_valid_color(plane->color))
		return (-1);
	return (0);
}

int	add_plane(t_lst_ref *objects, char *line)
{
	t_plane	*plane;
	char	**param;
	char	**point;
	char	**normal_vec;
	char	**color;

	if (split_parameter_plane(line, &param) == -1)
		return (-1);
	if (get_values_plane(&param, &point, &normal_vec, &color) == -1)
		return (-1);
	plane = malloc_or_print_error(sizeof(t_plane));
	if (plane == NULL)
	{
		free_values_plane(&param, &point, &normal_vec, &color);
		return (-1);
	}
	if (assign_values_plane(plane, point, normal_vec, color) == -1)
	{
		free_values_plane(&param, &point, &normal_vec, &color);
		return (-1);
	}
	free_values_plane(&param, &point, &normal_vec, &color);
	plane->reflect_factor = get_reflect_factor_from_str(param[4]);
	add_plane_list(objects, plane);
	return (0);
}
