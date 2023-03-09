#include "miniRT.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc_or_print_error(sizeof (t_scene));
	if (scene == NULL)
		return (NULL);
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
	return (scene);
}

void	*free_scene_null(t_scene *scene)
{
	if (scene->cam)
		scene->cam = free_null(scene->cam);
	free_lst(&scene->lights);
	free_lst(&scene->ambient_lights);
	free_lst(&scene->spheres);
	free_lst(&scene->planes);
	free_lst(&scene->cylinders);
	scene = free_null(scene);
	return (scene);
}
