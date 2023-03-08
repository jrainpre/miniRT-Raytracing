#include "miniRT.h"

void init_scene(t_scene *scene)
{
	scene->res = (t_resolution){.x = 0, .y = 0};

	scene->cam = NULL;
	scene->lights.head = NULL;
	scene->lights.last = NULL;
	scene->ambient_lights.head = NULL;
	scene->ambient_lights.last = NULL;
	scene->spheres.head = NULL;
	scene->spheres.last = NULL;
	scene->planes.head = NULL;
	scene->planes.last = NULL;
	scene->cylinders.head = NULL;
	scene->cylinders.last = NULL;
}

void free_scene(t_scene *scene)
{
	if (scene->cam)
		free(scene->cam);
	free_lst(&scene->lights);
	free_lst(&scene->ambient_lights);
	free_lst(&scene->spheres);
	free_lst(&scene->planes);
	free_lst(&scene->cylinders);
}
