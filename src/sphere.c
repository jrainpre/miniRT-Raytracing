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
	sphere->orig = get_vec_from_str_arr(orig);
	sphere->radius = ft_atof(parameters[2]) / 2;
	sphere->color = get_color_from_str_arr(color);
	sphere->reflect_factor = get_reflect_factor_from_str(parameters[4]);
	if (!is_valid_color(sphere->color))
	{
		sphere = free_null(sphere);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		color = free_arr_null(color);
		return (-1);
	}
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
	ft_lstlast(objects->head)->is_slected = 0;
	print_object(sphere, SPHERE);
	return (0);
}

float_t	get_sphere_distance_t(t_lst *object, t_ray ray)
{
	t_hit_calc	calc;
	t_vec3		orig_diff;
	t_sphere	*sphere;

	sphere = (t_sphere *)object->content;
	orig_diff = vec_sub(ray.orig, sphere->orig);
	calc.a = scalar_prod(ray.dir, ray.dir);
	calc.b = 2.0 * scalar_prod(orig_diff, ray.dir);
	calc.c = \
		scalar_prod(orig_diff, orig_diff) - sphere->radius * sphere->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (0);
	if (calc_distant_t(&calc) == -1)
		return (0);
	return (calc.distance_t);
}

int	calc_distant_t(t_hit_calc *calc)
{
	float_t	t1;
	float_t	t2;
	float_t	smallest_t;

	t1 = (-calc->b - sqrt(calc->discriminant)) / (2.0f * calc->a);
	t2 = (-calc->b + sqrt(calc->discriminant)) / (2.0f * calc->a);
	smallest_t = fmin(t1, t2);
	calc->distance_t = smallest_t;
	if (calc->distance_t < 0)
		return (-1);
	return (0);
}
