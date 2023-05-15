#include "miniRT.h"

t_vec3	reflect_vec_sphere(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3	unit_normal;
	t_vec3	b;
	t_vec3	reflection;
	t_vec3	to_light;

	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal = unit_vec3(vec_sub(hit_point, sphere->orig));
	b = vec_mult(unit_normal, 2 * scalar_prod(unit_normal, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_vec3	reflect_vec_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene)
{
	t_vec3	unit_normal;
	t_vec3	b;
	t_vec3	reflection;
	t_vec3	to_light;

	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal = unit_vec3(plane->normal_vec);
	b = vec_mult(unit_normal, 2 * scalar_prod(unit_normal, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_vec3	reflect_vec_cyl(t_hit_info *hit_info, t_cylinder *cyl, t_scene *scene)
{
	t_vec3	to_light;
	t_vec3	reflect;

	to_light = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
	reflect = vec_sub(vec_mult(hit_info->normal, 2
				* scalar_prod(hit_info->normal, to_light)), to_light);
	return (reflect);
}

int	check_in_shade(t_hit_info *hit, t_scene *scene)
{
	t_ray	ray;
	
	if (hit->is_inside_hit == 1)
		return (0);
	ray.dir = unit_vec3(vec_sub(scene->light->orig, hit->hitpoint));
	ray.orig = vec_add(hit->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	if (get_closest_hit_light(scene, ray) == NULL)
		return (1);
	return (0);
}
