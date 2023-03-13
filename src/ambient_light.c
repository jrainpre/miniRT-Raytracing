#include "miniRT.h"

t_ambient_light	*init_ambient_light(t_ambient_light *ambient_light)
{
	ambient_light = malloc_or_print_error(sizeof (t_ambient_light));
	if (ambient_light == NULL)
		return (NULL);
	ambient_light->color = (t_color){1.0, 1.0, 1.0, 1.0};
	ambient_light->ratio = 0.2;
	return (ambient_light);
}
