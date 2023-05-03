#include "miniRT.h"

t_color get_diffuse_color_object(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_diffuse_color_sphere(scene, object, hit_info));
	else if (type == PLANE)
		return (get_diffuse_light_plane(scene, object, hit_info));
	else if (type == CYLINDER)
		return (get_diffuse_light_cylinder(scene, object, hit_info));
	return ((t_color){0, 0, 0, 0});
}

t_color get_diffuse_color_sphere(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
    t_sphere *sphere;
    float_t angle;
    t_color act_color;
    t_ray ray;

    ray.dir = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
    ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
    ray.dir = unit_vec3(vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
    sphere = (t_sphere *)object->content;
    angle = get_light_angle(hit_info->hitpoint, sphere, scene);
    if (get_closest_hit_light(scene, ray) != NULL)
        angle = 0;
    act_color = color_mult(sphere->color, angle * scene->light->ratio);
    return (act_color);
}



t_color	get_diffuse_light_plane(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_plane	*plane;
	float_t	angle;
	t_color	act_color;
	t_ray ray;

	ray.dir = vec_sub(scene->light->orig, hit_info->hitpoint);
	ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	ray.dir = unit_vec3(vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
	plane = (t_plane *)object->content;
	angle = get_light_angle_plane(hit_info->hitpoint, plane, scene);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(plane->color, angle * scene->light->ratio);
	return (act_color);
}

t_color get_diffuse_light_cylinder(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_cylinder *cylinder;
	float_t angle;
	t_color act_color;
	t_ray ray;

	ray.dir = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
	ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, 0.01));
	ray.dir = unit_vec3(vec_add(ray.dir, vec_mult(random_in_unit_sphere(), SHADOW_SOFT_MULTIPLIER)));
	cylinder = (t_cylinder *)object->content;
	angle = get_light_angle_cylinder(hit_info, cylinder, scene);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	act_color = color_mult(cylinder->color, angle * scene->light->ratio);
	return (act_color);
}