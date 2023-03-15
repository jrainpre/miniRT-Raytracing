#include "miniRT.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc_or_print_error(sizeof (t_scene));
	if (scene == NULL)
		return (NULL);
	scene->cam = NULL;
	scene->objects = malloc_or_print_error(sizeof (t_lst_ref));
	if (scene->objects == NULL)
		return (NULL);
	scene->objects->head = NULL;
	scene->objects->last = NULL;
	return (scene);
}

void	*free_scene_null(t_scene *scene)
{
	if (scene == NULL)
		return (NULL);
	scene->cam = free_null(scene->cam);
	scene->objects = free_lst_null(scene->objects);
	scene->light = free_null(scene->light);
	scene->ambient_light = free_null(scene->ambient_light);
	scene = free_null(scene);
	return (scene);
}
