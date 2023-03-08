#include "miniRT.h"


void fill_dummy_scene(t_scene *scene)
{
	scene->res = (t_resolution){.x = 1920, .y = 1080};
	//camera
	scene->cam = (t_camera *)malloc(sizeof(t_camera));
	scene->cam->orig = (t_pt){.x = 0, .y = 0, .z = 0};
	scene->cam->orientation = (t_pt){.x = 0, .y = 0, .z = 1};
	scene->cam->fov = 70;
	//spheres
	t_sphere *sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->orig = (t_pt){.x = 0, .y = 0, .z = 0};
	sphere->radius = 10;
	sphere->color = (t_color){.r = 255, .g = 0, .b = 0};
	ft_add_lst_last(ft_lstnew(sphere), scene->spheres);
}