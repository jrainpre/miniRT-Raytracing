#include "miniRT.h"

int	fill_dummy_scene(t_scene *scene)
{
	scene->res = (t_resolution){.x = 1280, .y = 720};
	scene->cam = init_camera(scene->cam);
	if (scene->cam == NULL)
		return (-1);
	scene->light = init_light(scene->light);
	if (scene->light == NULL)
		return (-1);
	scene->ambient_light = init_ambient_light(scene->ambient_light);
	if (scene->ambient_light == NULL)
		return (-1);
	if (add_sphere(scene->objects, (t_pt3){0, 0, -100}, 20.0f, (t_color){0, 255, 0, 1}) == -1)
		return (-1);
	return (0);
}

int	add_sphere(t_lst_ref *objects, t_pt3 orig, float_t r, t_color col)
{
	t_sphere	*sphere;

	sphere = malloc_or_print_error(sizeof (t_sphere));
	if (sphere == NULL)
		return (-1);
	sphere->orig = orig;
	sphere->radius = r;
	sphere->color = col;

	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
	return (0);
}

t_camera	*init_camera(t_camera *cam)
{
	cam = malloc_or_print_error(sizeof (t_camera));
	if (cam == NULL)
		return (NULL);
	cam->orig = (t_pt3){0, 0, 10};
	cam->orientation = (t_vec3){0, 0, -1};
	cam->fov = 70;
	cam->sensor_height = 2;
	cam->sensor_width = (WIN_W / WIN_H) * cam->sensor_height;
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
