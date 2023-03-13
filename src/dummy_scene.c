#include "miniRT.h"

int	fill_dummy_scene(t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	scene->cam = init_camera(data->win, "C 0.0,0.0,10.0    0,0,-1    70");
	if (scene->cam == NULL)
		return (-1);
	scene->light = init_light(scene->light);
	if (scene->light == NULL)
		return (-1);
	scene->ambient_light = init_ambient_light(scene->ambient_light);
	if (scene->ambient_light == NULL)
		return (-1);
	if (add_sphere(scene->objects, "sp    0.0,0.0,-100.0    50    129,0,0") == -1)
		return (-1);
	if (add_sphere(scene->objects, "sp    -30,0.0,-50.0    3    80,80,80") == -1)
		return (-1);
	if (add_plane(scene->objects, "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225") == -1)
		return (-1);
	if (add_cylinder(scene->objects, "cy   50.0,0.0,20.6  0.0,0.0,1.0 14.2   21.42   10,0,255") == -1)
		return (-1);
	return (1);
}
