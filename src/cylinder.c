#include "miniRT.h"

int	split_parameter_cyl(char *line, char ***param)
{
	*param = ft_split(line, ' ');
	if (*param == NULL)
		return (-1);
	return (0);
}

int	assign_parameter_cyl(char ***param, char ***orig, char ***axis, \
	char ***color)
{
	*orig = ft_split((*param)[1], ',');
	if (*orig == NULL)
	{
		*param = free_arr_null(*param);
		return (-1);
	}
	*axis = ft_split((*param)[2], ',');
	if (*axis == NULL)
	{
		*param = free_arr_null(*param);
		*orig = free_arr_null(*orig);
		return (-1);
	}
	*color = ft_split((*param)[5], ',');
	if (*color == NULL)
	{
		*param = free_arr_null(*param);
		*orig = free_arr_null(*orig);
		*axis = free_arr_null(*axis);
		return (-1);
	}
	return (0);
}

t_cylinder	*create_cylinder(char **param, char **orig, char **axis,
		char **color)
{
	t_cylinder	*cylinder;

	cylinder = malloc_or_print_error(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	cylinder->orig = get_vec_from_str_arr(orig);
	cylinder->axis = get_vec_from_str_arr(axis);
	if (!is_normalized(cylinder->axis))
	{
		cylinder = free_null(cylinder);
		return (NULL);
	}
	cylinder->radius = ft_atof(param[3]) / 2;
	cylinder->height = ft_atof(param[4]);
	cylinder->color = get_color_from_str_arr(color);
	if (!is_valid_color(cylinder->color))
	{
		cylinder = free_null(cylinder);
		return (NULL);
	}
	cylinder->reflect_factor = get_reflect_factor_from_str(param[6]);
	return (cylinder);
}

void	free_all_cyl(char **param, char **orig, char **axis, char **color)
{
	param = free_arr_null(param);
	orig = free_arr_null(orig);
	axis = free_arr_null(axis);
	color = free_arr_null(color);
}

int	add_cylinder(t_lst_ref *objects, char *line)
{
	t_cylinder	*cylinder;
	char		**param;
	char		**orig;
	char		**axis;
	char		**color;

	if (split_parameter_cyl(line, &param) == -1)
		return (-1);
	if (assign_parameter_cyl(&param, &orig, &axis, &color) == -1)
		return (-1);
	cylinder = create_cylinder(param, orig, axis, color);
	if (cylinder == NULL)
	{
		free_all_cyl(param, orig, axis, color);
		return (-1);
	}
	free_all_cyl(param, orig, axis, color);
	ft_add_lst_last(ft_lstnew(cylinder), objects);
	ft_lstlast(objects->head)->type = CYLINDER;
	ft_lstlast(objects->head)->is_slected = 0;
	return (0);
}
