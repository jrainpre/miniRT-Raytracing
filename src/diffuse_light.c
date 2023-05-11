#include "miniRT.h"

t_color	diffuse_light_obj(t_scene *scene, t_lst *obj, t_hit_info *hit)
{
	t_object_type	type;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;

	type = obj->type;
	if (type == SPHERE)
	{
		sphere = (t_sphere *)obj->content;
		return (diffuse_light_sphere(scene, sphere, hit));
	}
	else if (type == PLANE)
	{
		plane = (t_plane *)obj->content;
		return (diffuse_light_plane(scene, plane, hit));
	}
	else if (type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->content;
		return (diffuse_light_cyl(scene, cylinder, hit));
	}
	return ((t_color){0, 0, 0, 0});
}

t_color	diffuse_light_sphere(t_scene *scene, t_sphere *sphere, t_hit_info *hit)
{
	float_t	angle;
	t_color	act_color;
	t_ray	ray;

	ray.dir = unit_vec3(vec_sub(scene->light->orig, hit->hitpoint));
	ray.orig = vec_add(hit->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = unit_vec3(vec_add(ray.dir, \
		vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
	angle = get_light_angle(hit->hitpoint, sphere, scene);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(sphere->color, angle * scene->light->ratio);
	return (act_color);
}

t_color	diffuse_light_plane(t_scene *scene, t_plane *plane, t_hit_info *hit)
{
	float_t	angle;
	t_color	act_color;
	t_ray	ray;

	ray.dir = vec_sub(scene->light->orig, hit->hitpoint);
	ray.orig = vec_add(hit->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = unit_vec3(vec_add(ray.dir, \
		vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
	angle = get_light_angle_plane(hit->hitpoint, plane, scene);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(plane->color, angle * scene->light->ratio);
	return (act_color);
}

t_color	diffuse_light_cyl(t_scene *scene, t_cylinder *cyl, t_hit_info *hit)
{
	float_t	angle;
	t_color	act_color;
	t_ray	ray;

	ray.dir = unit_vec3(vec_sub(scene->light->orig, hit->hitpoint));
	ray.orig = vec_add(hit->hitpoint, vec_mult(ray.dir, 0.01));
	ray.dir = unit_vec3(vec_add(ray.dir, \
		vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
	angle = get_light_angle_cyl(hit, cyl, scene);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(cyl->color, angle * scene->light->ratio);
	return (act_color);
}
