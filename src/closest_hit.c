#include "miniRT.h"

void	get_closest_hit(t_scene *scene, t_ray ray, t_hit_info *hit_info)
{
	t_lst		*list;
	t_lst		*closest_hit;
	float_t		closest_t;
	float_t		distance_t;

	closest_t = INFINITY;
	hit_info->object = NULL;
	list = scene->objects->head;
	while (list)
	{
		distance_t = get_distance_t(list, ray);
		if (distance_t > 0.0f && distance_t < closest_t)
		{
			closest_t = distance_t;
			hit_info->object = list;
			hit_info->ray = ray;
		}
		list = list->next;
	}
	hit_info->distance = closest_t;
}

int	is_in_fornt_of_light(t_scene *scene, t_ray ray, float_t distance_t)
{
	t_vec3	hit_to_light;
	t_vec3	light_direction;

	light_direction = unit_vec3(vec_sub(scene->light->orig, ray.orig));
	hit_to_light = vec_sub(scene->light->orig, \
		vec_add(ray.orig, vec_mult(ray.dir, distance_t)));
	if (scalar_prod(light_direction, hit_to_light) >= 0)
		return (1);
	return (0);
}

t_lst	*get_closest_hit_light(t_scene *scene, t_ray ray)
{
	t_lst	*list;
	t_lst	*closest_hit;
	float_t	distance_t;
	float_t	closest_t;

	closest_t = INFINITY;
	closest_hit = NULL;
	list = scene->objects->head;
	while (list)
	{
		distance_t = get_distance_t(list, ray);
		if (distance_t > 0.0f && distance_t < closest_t)
		{
			if (is_in_fornt_of_light(scene, ray, distance_t))
			{
				closest_t = distance_t;
				closest_hit = list;
			}
		}
		list = list->next;
	}
	return (closest_hit);
}

float_t	get_distance_t(t_lst *object, t_ray ray)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_sphere_distance_t(object, ray));
	else if (type == PLANE)
		return (get_plane_distance_t(object, ray));
	else if (type == CYLINDER)
		return (get_cylinder_distance_t((t_cylinder *)object->content, ray));
	return (INFINITY);
}

t_color	get_color_hitpoint(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	result;

	if (object->is_slected)
		return ((t_color){1.0f, 0.0f, 0.0f});
	ambient = ambient_light_obj(scene, object);
	diffuse = diffuse_light_obj(scene, object, hit_info);
	specular = specular_light_obj(scene, object, hit_info);
	result = color_add(ambient, diffuse);
	result = color_add(result, specular);
	result = color_clamp(result, 0.0f, 1.0f);
	return (result);
}	
