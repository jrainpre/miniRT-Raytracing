#include "miniRT.h"

int	fill_scene(t_scene *scene, t_lst_ref *scene_lines, t_resolution win)
{
	char	*line;
	t_lst	*runner;

	runner = scene_lines->head;
	while (runner)
	{
		line = (char *)runner->content;
		if (runner->type == CAMERA)
		{
			scene->cam = init_camera(win, line);
			if (scene->cam == NULL)
				return (-1);
		}
		else if (runner->type == LIGHT)
		{
			scene->light = init_light(line);
			if (scene->light == NULL)
				return (-1);
		}
		else if (runner->type == AMBIENT_LIGHT)
		{
			scene->ambient_light = init_ambient_light(line);
			if (scene->ambient_light == NULL)
				return (-1);
		}
		else if (runner->type == SPHERE)
		{
			if (add_sphere(scene->objects, line) == -1)
				return (-1);
		}
		else if (runner->type == PLANE)
		{
			if (add_plane(scene->objects, line) == -1)
				return (-1);
		}
		else if (runner->type == CYLINDER)
		{
			if (add_cylinder(scene->objects, line) == -1)
				return (-1);
		}
		runner = runner->next;
	}
	return (1);
}
