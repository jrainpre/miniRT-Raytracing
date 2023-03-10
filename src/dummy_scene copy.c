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
	if (add_sphere(scene->objects, "sp    3.1415,2.0000001,-100.23    50    10,0,255") == -1)
		return (-1);
	return (0);
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
	printf("line: \"%s\"\n", line);
	printf("orig.x: \"%19.15f\"\n", sphere->orig.x);
	printf("orig.y: \"%19.15f\"\n", sphere->orig.y);
	printf("orig.z: \"%19.15f\"\n", sphere->orig.z);
	printf("radius: \"%19.15f\"\n", sphere->radius);
	printf("color.x: \"%19.15f\"\n", sphere->color.x);
	printf("color.y: \"%19.15f\"\n", sphere->color.y);
	printf("color.z: \"%19.15f\"\n", sphere->color.z);
	printf("color.a: \"%19.15f\"\n", sphere->color.a);
	return (0);
}

t_camera	*init_camera(t_camera *cam, t_resolution win)
{
	cam = malloc_or_print_error(sizeof (t_camera));
	if (cam == NULL)
		return (NULL);
	cam->orig = (t_pt3){0, 0, 10};
	cam->orientation = (t_vec3){0, 0, -1};
	cam->fov = 70;
	cam->sensor_height = 2;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) * cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) / tanf(deg_to_rad(cam->fov / 2.0));
	cam->vertical = (t_vec3){0, cam->sensor_height, 0};
	cam->horizontal = (t_vec3){cam->sensor_width, 0, 0};
	cam->lower_left_corner = vec_sub(cam->orig, vec_add(vec_add(vec_div(cam->horizontal, 2), vec_div(cam->vertical, 2)), (t_vec3){0, 0, cam->focal_length}));
	return (cam);
}

t_light	*init_light(t_light *light)
{
	light = malloc_or_print_error(sizeof (t_light));
	if (light == NULL)
		return (NULL);
	light->orig = (t_pt3){-40.0, 50, 0.0};
	light->color = (t_color){1.0, 1.0, 1.0, 1.0};
	light->ratio = 0.6;
	return (light);
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
