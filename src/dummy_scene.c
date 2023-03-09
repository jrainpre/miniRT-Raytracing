#include "miniRT.h"

void	fill_dummy_scene(t_scene *scene)
{
	t_sphere	*sphere;

	scene->res = (t_resolution){.x = 1920, .y = 1080};

	//camera
	scene->cam = malloc_or_print_error(sizeof (t_camera));
	if (scene->cam == NULL)
		return ;
	scene->cam->orig = (t_pt){0, 0, 10, NOCOLOR};
	scene->cam->orientation = (t_vec){0, 0, -1, NOCOLOR};
	scene->cam->fov = 70;
	scene->cam->sensor_height = 2;
	scene->cam->sensor_width = (WIN_W / WIN_H) * scene->cam->sensor_height;
	scene->cam->focal_length = (scene->cam->sensor_width / 2) / tanf(deg_to_rad(scene->cam->fov / 2.0));
	scene->cam->vertical = (t_vec){0, scene->cam->sensor_height, 0, NOCOLOR};
	scene->cam->horizontal = (t_vec){scene->cam->sensor_width, 0, 0, NOCOLOR};
	scene->cam->lower_left_corner = vec_sub(scene->cam->orig, vec_add(vec_add(vec_div(scene->cam->horizontal, 2), vec_div(scene->cam->vertical, 2)), (t_vec){0, 0, scene->cam->focal_length, NOCOLOR}));

	//spheres
	sphere = malloc_or_print_error(sizeof(t_sphere));
	if (sphere == NULL)
		return ;
	sphere->orig = (t_pt){0, 0, -100, NOCOLOR};
	sphere->radius = 40.0;
	sphere->color = (t_color){0, 255, 0};

	ft_add_lst_last(ft_lstnew(sphere), &scene->spheres);
}
