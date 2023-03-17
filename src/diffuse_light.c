#include "miniRT.h"

t_color get_diffuse_color_object(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_diffuse_color_sphere(scene, object, hitpoint));
	// else if (type == PLANE)
	// 	return (get_diffuse_light_plane(scene, object, hitpoint));
	// else if (type == CYLINDER)
	// 	return (get_diffuse_light_cylinder(scene, object, hitpoint));
	return ((t_color){0, 0, 0, 0});
}

t_color get_diffuse_color_sphere(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_sphere *sphere;
	float_t angle;
	t_color act_color;

	sphere = (t_sphere *)object->content;
	angle = get_light_angle(hitpoint, sphere, scene);
	act_color = color_mult(sphere->color, angle * scene->light->ratio);
	return (act_color);
}
