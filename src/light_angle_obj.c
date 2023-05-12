#include "miniRT.h"

float_t	get_light_angle(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3	unit_light;
	t_vec3	normal_hit_point;
	t_vec3	unit_normal_hit_point;
	float_t	angle;

	normal_hit_point = vec_sub(hit_point, sphere->orig);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

float_t	get_light_angle_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene)
{
	t_vec3	unit_light;
	t_vec3	normal_hit_point;
	t_vec3	unit_normal_hit_point;
	float_t	angle;

	(void)hit_point;
	normal_hit_point = vec_mult(plane->normal_vec, -1);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

float_t	get_light_angle_cyl(t_hit_info *hit_info, t_cylinder *cyl, \
	t_scene *scene)
{
	t_vec3	unit_light;
	float_t	angle;

	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(hit_info->normal, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}