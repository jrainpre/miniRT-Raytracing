#include "miniRT.h"

t_color	follow_ray(t_scene *scene, t_ray ray)
{
	t_hit_info	hit_info;
	t_color		color;
	float_t		factor;
	int			i;
	t_color		act_color;

	act_color = (t_color){0, 0, 0, 0};
	factor = 1.0f;
	i = -1;
	while (++i < 2)
	{
		get_closest_hit(scene, ray, &hit_info);
		if (hit_info.object == NULL)
			return (act_color);
		hit_info.hitpoint = vec_add(ray.orig, \
			vec_mult(ray.dir, hit_info.distance));
		get_normal_to_surface(hit_info.object, &hit_info);
		color = get_color_hitpoint(scene, hit_info.object, &hit_info);
		act_color = color_add(color_mult(color, factor), act_color);
		factor *= 0.7 * get_reflect_factor(hit_info.object);
		ray.orig = vec_add(ray.orig, vec_mult(hit_info.normal, VEC_OFFSET));
		ray.dir = calulate_fuzzed_reflected(ray.dir, hit_info.normal, 1 - \
			get_reflect_factor(hit_info.object));
	}
	return (act_color);
}

t_vec3	calulate_fuzzed_reflected(t_vec3 direction, t_vec3 normal, double fuzz)
{
	t_vec3	reflected;
	t_vec3	fuzz_vec;
	t_vec3	fuzzed_reflected;

	reflected = get_reflect_ray(unit_vec3(direction), normal);
	fuzz_vec = vec_mult(random_in_unit_sphere(), fuzz);
	fuzzed_reflected = vec_add(reflected, fuzz_vec);
	return (fuzzed_reflected);
}

float_t	get_reflect_factor(t_lst *object)
{
	if (object->type == SPHERE)
		return (((t_sphere *)object->content)->reflect_factor);
	else if (object->type == PLANE)
		return (((t_plane *)object->content)->reflect_factor);
	else if (object->type == CYLINDER)
		return (((t_cylinder *)object->content)->reflect_factor);
	else
		return (0);
}

void	get_normal_to_surface(t_lst *object, t_hit_info *hit_info)
{
	t_vec3		normal;
	t_sphere	*sphere;
	t_plane		*plane;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->content;
		normal = vec_sub(hit_info->hitpoint, sphere->orig);
		hit_info->normal = unit_vec3(normal);
	}
	else if (object->type == PLANE)
	{
		plane = (t_plane *)object->content;
		normal = plane->normal_vec;
		hit_info->normal = unit_vec3(normal);
	}
	else if (object->type == CYLINDER)
		get_normal_cylinder(hit_info, (t_cylinder *)object->content);
	else
		hit_info->normal = (t_vec3){0, 0, 0};
}

t_vec3	get_reflect_ray(t_vec3 vector, t_vec3 normal)
{
	t_vec3	reflection;

	reflection = vec_sub(vector, \
		vec_mult(normal, 2 * scalar_prod(vector, normal)));
	return (reflection);
}
