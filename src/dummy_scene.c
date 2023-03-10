#include "miniRT.h"

void	fill_dummy_scene(t_scene *scene)
{
	scene->res = (t_resolution){.x = 1280, .y = 720};

	//camera
	scene->cam = malloc_or_print_error(sizeof (t_camera));
	if (scene->cam == NULL)
		return ;
	scene->cam->orig = (t_pt3){0, 0, 10};
	scene->cam->orientation = (t_vec3){0, 0, -1};
	scene->cam->fov = 70;
	scene->cam->sensor_height = 2;
	scene->cam->sensor_width = (WIN_W / WIN_H) * scene->cam->sensor_height;
	scene->cam->focal_length = (scene->cam->sensor_width / 2) / tanf(deg_to_rad(scene->cam->fov / 2.0));
	scene->cam->vertical = (t_vec3){0, scene->cam->sensor_height, 0};
	scene->cam->horizontal = (t_vec3){scene->cam->sensor_width, 0, 0};
	scene->cam->lower_left_corner = vec_sub(scene->cam->orig, vec_add(vec_add(vec_div(scene->cam->horizontal, 2), vec_div(scene->cam->vertical, 2)), (t_vec3){0, 0, scene->cam->focal_length}));

	//spheres
	add_sphere(scene->objects, (t_pt3){0, 0, -100}, 20.0f, (t_color){0, 255, 0, 1});
}

void	add_sphere(t_lst_ref *objects, t_pt3 orig, float_t r, t_color col)
{
	t_sphere	*sphere;

	sphere = malloc_or_print_error(sizeof (t_sphere));
	if (sphere == NULL)
		return ;
	sphere->orig = orig;
	sphere->radius = r;
	sphere->color = col;

	ft_add_lst_last(ft_lstnew(sphere), objects);
	ft_lstlast(objects->head)->type = SPHERE;
}
