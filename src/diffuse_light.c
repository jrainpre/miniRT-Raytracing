#include "miniRT.h"

t_color get_diffuse_color_object(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_diffuse_color_sphere(scene, object, hitpoint));
	else if (type == PLANE)
		return (get_diffuse_light_plane(scene, object, hitpoint));
	else if (type == CYLINDER)
		return (get_diffuse_light_cylinder(scene, object, hitpoint));
	return ((t_color){0, 0, 0, 0});
}

int is_closest_to_light(t_lst *head, t_lst *object, t_vec3 hitpoint, t_vec3 light)
{
	t_lst *tmp;
	t_vec3 tmp_hitpoint;
	float_t distance;
	float_t tmp_distance;
	t_ray ray;

	ray.orig = light;
	ray.dir = vec_sub(hitpoint, light);
	distance = vec_length(vec_sub(hitpoint, light));
	tmp = head;
	while (tmp)
	{
		if (tmp != object)
		{
			tmp_hitpoint = get_hitpoint_object(tmp, get_distance_t(tmp, ray), ray);
			tmp_distance = vec_length(vec_sub(tmp_hitpoint, light));
			if (tmp_distance < distance)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

t_color get_diffuse_color_sphere(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_sphere *sphere;
	float_t angle;
	t_color act_color;
	t_ray ray;

	ray.orig = hitpoint;
	ray.dir = vec_sub(scene->light->orig, hitpoint);
	ray.orig = vec_add(ray.orig, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER));
	sphere = (t_sphere *)object->content;
	angle = get_light_angle(hitpoint, sphere, scene);
	if (get_closest_hit(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(sphere->color, angle * scene->light->ratio);
	return (act_color);
}

t_color	get_diffuse_light_plane(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_plane	*plane;
	float_t	angle;
	t_color	act_color;


	t_ray ray;

	ray.orig = hitpoint;
	ray.dir = vec_sub(scene->light->orig, hitpoint);
	ray.orig = vec_add(ray.orig, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER));
	plane = (t_plane *)object->content;
	angle = get_light_angle_plane(hitpoint, plane, scene);
	if (get_closest_hit(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(plane->color, angle * scene->light->ratio);
	return (act_color);
}

t_color get_diffuse_light_cylinder(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_cylinder *cylinder;
	float_t angle;
	t_color act_color;
	t_ray ray;

	ray.orig = hitpoint;
	ray.dir = vec_sub(scene->light->orig, hitpoint);
	ray.orig = vec_add(ray.orig, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER));
	cylinder = (t_cylinder *)object->content;
	angle = get_light_angle_cylinder(hitpoint, cylinder, scene);
	if (get_closest_hit(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(cylinder->color, angle * scene->light->ratio);
	return (act_color);
}