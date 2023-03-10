#include "miniRT.h"

int	fill_dummy_scene(t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	scene->cam = init_camera(scene->cam, data->win);
	if (scene->cam == NULL)
		return (-1);
	scene->light = init_light(scene->light);
	if (scene->light == NULL)
		return (-1);
	scene->ambient_light = init_ambient_light(scene->ambient_light);
	if (scene->ambient_light == NULL)
		return (-1);
	if (add_sphere(scene->objects, "sp    0.0,0.0,-100.0    50    129,0,0") == -1)
		return (-1);
	if (add_sphere(scene->objects, "sp    -30,0.0,-50.0    3    80,80,80") == -1)
		return (-1);
	return (1);
}

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
	sphere->color = (t_color){ft_atoi(color[0]) / 255.0f, ft_atoi(color[1]) / 255.0f, ft_atoi(color[2]) / 255.0f, 1};
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	color = free_arr_null(color);
	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
	return (0);
}

t_ambient_light	*init_ambient_light(t_ambient_light *ambient_light)
{
	ambient_light = malloc_or_print_error(sizeof (t_ambient_light));
	if (ambient_light == NULL)
		return (NULL);
	ambient_light->color = (t_color){1.0, 1.0, 1.0, 1.0};
	ambient_light->ratio = 0.2;
	return (ambient_light);
}
