#include "miniRT.h"

int	split_param_sphere(char *line, char ***param, char ***orig, char ***color)
{
	*param = ft_split(line, ' ');
	if (*param == NULL)
		return (-1);
	*orig = ft_split((*param)[1], ',');
	if (*orig == NULL)
	{
		*param = free_arr_null(*param);
		return (-1);
	}
	*color = ft_split((*param)[3], ',');
	if (*color == NULL)
	{
		*param = free_arr_null(*param);
		*orig = free_arr_null(*orig);
		return (-1);
	}
	return (0);
}

t_sphere	*create_sphere(char **param, char **orig, char **color)
{
	t_sphere	*sphere;

	sphere = malloc_or_print_error(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->orig = get_vec_from_str_arr(orig);
	sphere->radius = ft_atof(param[2]) / 2;
	sphere->color = get_color_from_str_arr(color);
	sphere->reflect_factor = get_reflect_factor_from_str(param[4]);
	if (!is_valid_color(sphere->color))
	{
		sphere = free_null(sphere);
		param = free_arr_null(param);
		orig = free_arr_null(orig);
		color = free_arr_null(color);
		return (NULL);
	}
	return (sphere);
}

int	add_sphere(t_lst_ref *objects, char *line)
{
	t_sphere	*sphere;
	char		**param;
	char		**orig;
	char		**color;

	if (split_param_sphere(line, &param, &orig, &color) == -1)
		return (-1);
	sphere = create_sphere(param, orig, color);
	if (sphere == NULL)
		return (-1);
	param = free_arr_null(param);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
	ft_lstlast(objects->head)->is_slected = 0;
	return (0);
}

float_t	get_sphere_distance_t(t_lst *object, t_ray ray, t_hit_info *hit_info)
{
	t_hit_calc	calc;
	t_vec3		orig_diff;
	t_sphere	*sphere;

	sphere = (t_sphere *)object->content;
	orig_diff = vec_sub(ray.orig, sphere->orig);
	calc.a = scalar_prod(ray.dir, ray.dir);
	calc.b = 2.0 * scalar_prod(orig_diff, ray.dir);
	calc.c = scalar_prod(orig_diff, orig_diff) \
		- sphere->radius * sphere->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (0);
	if (calc_distant_t(&calc, hit_info) == -1)
		return (0);
	return (calc.distance_t);
}

int	calc_distant_t(t_hit_calc *calc, t_hit_info *hit_info)
{
	float_t	t1;
	float_t	t2;

	t1 = (-calc->b - sqrt(calc->discriminant)) / (2.0f * calc->a);
	t2 = (-calc->b + sqrt(calc->discriminant)) / (2.0f * calc->a);
	if (t1 > 0 && t2 > 0)
	{
		hit_info->is_inside_hit = 0;
		calc->distance_t = fmin(t1, t2);
	}
	else if (t1 > 0)
	{
		hit_info->is_inside_hit = 1;
		calc->distance_t = t1;
	}
	else if (t2 > 0)
	{
		hit_info->is_inside_hit = 1;
		calc->distance_t = t2;
	}
	else
		return (-1);
	return (0);
}
