#include "miniRT.h"

t_light	*init_light(t_light *light)
{
	light = malloc_or_print_error(sizeof (t_light));
	if (light == NULL)
		return (NULL);
	light->orig = (t_pt3){100, 100, 50};
	light->color = (t_color){1.0, 1.0, 1.0, 1.0};
	light->ratio = 1;
	return (light);
}

void	translate_light(t_light *light, t_vec3 vec)
{
	light->orig = vec_add(light->orig, vec);
}
