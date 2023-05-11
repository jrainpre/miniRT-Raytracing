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
	if (!is_valid_ratio(ambient_light->ratio))
	{
		ambient_light = free_null(ambient_light);
		parameters = free_arr_null(parameters);
		color = free_arr_null(color);
		return (NULL);
	}
	ambient_light->color = get_color_from_str_arr(color);
	if (!is_valid_color(ambient_light->color))
	{
		ambient_light = free_null(ambient_light);
		parameters = free_arr_null(parameters);
		color = free_arr_null(color);
		return (NULL);
	}
	parameters = free_arr_null(parameters);
	color = free_arr_null(color);
	return (ambient_light);
}

t_color	get_ambient_color_object(t_scene *scene, t_lst *object)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_ambient_color_sphere(scene, object));
	else if (type == PLANE)
		return (get_ambient_color_plane(scene, object));
	else if (type == CYLINDER)
		return (get_ambient_light_cylinder(scene, object));
	return ((t_color){0, 0, 0, 0});
}

t_color	get_ambient_color_sphere(t_scene *scene, t_lst *object)
{
	t_sphere	*sphere;
	t_color		ambient;

	sphere = (t_sphere *)object->content;
	ambient = color_mult_color(sphere->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}

t_color	get_ambient_color_plane(t_scene *scene, t_lst *object)
{
	t_plane	*plane;
	t_color	ambient;

	plane = (t_plane *)object->content;
	ambient = color_mult_color(plane->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}

t_color	get_ambient_light_cylinder(t_scene *scene, t_lst *object)
{
	t_cylinder	*cylinder;
	t_color		ambient;

	cylinder = (t_cylinder *)object->content;
	ambient = color_mult_color(cylinder->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}
