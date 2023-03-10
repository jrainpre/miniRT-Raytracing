#include "miniRT.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc_or_print_error(sizeof (t_scene));
	if (scene == NULL)
		return (NULL);
	scene->res = (t_resolution){.x = 0, .y = 0};
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
	scene->cam = free_null(scene->cam);
	scene->objects = free_lst_null(scene->objects);
	scene = free_null(scene);
	return (scene);
}
