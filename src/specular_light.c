#include "miniRT.h"

t_color get_specular_color_object(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_specular_color_sphere(scene, object, hit_info));
	else if (type == PLANE)
		return (get_specular_color_plane(scene, object, hit_info));
	else if (type == CYLINDER)
		return (get_specular_color_cylinder(scene, object, hit_info));
	return ((t_color){0, 0, 0, 0});
}

t_vec3 get_reflection_vec_sphere(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3 unit_normal_hit_point;
	t_vec3 b;
	t_vec3 reflection;
	t_vec3 to_light;

	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal_hit_point = unit_vec3(vec_sub(hit_point, sphere->orig));
	b = vec_mult(unit_normal_hit_point, 2 * scalar_prod(unit_normal_hit_point, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_vec3 get_reflection_vec_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene)
{
	t_vec3 unit_normal_hit_point;
	t_vec3 b;
	t_vec3 reflection;
	t_vec3 to_light;

	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal_hit_point = unit_vec3(plane->normal_vec);
	b = vec_mult(unit_normal_hit_point, 2 * scalar_prod(unit_normal_hit_point, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_color get_specular_color_plane(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_vec3 reflection;
	t_vec3 to_camera;
	t_vec3 to_light;
	float_t angle;
	float_t factor;
	t_plane *plane;
	t_color act_color;
		t_ray ray;

	ray.dir = vec_sub(scene->light->orig, hit_info->hitpoint);
	ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	plane = (t_plane *)object->content;
	reflection = unit_vec3(get_reflection_vec_plane(hit_info->hitpoint, plane, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit_info->hitpoint));
	to_light = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
	angle = scalar_prod(to_camera, reflection);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, plane->reflect_factor * 120);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	factor = plane->reflect_factor * 128 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor * scene->light->ratio);
	return (act_color);
}

t_color get_specular_color_sphere(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_vec3 reflection;
	t_vec3 to_camera;
	t_vec3 to_light;
	float_t angle;
	float_t factor;
	t_sphere *sphere;
	t_color act_color;
	t_ray ray;

	ray.dir = vec_sub(scene->light->orig, hit_info->hitpoint);
	ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	sphere = (t_sphere *)object->content;
	reflection = unit_vec3(get_reflection_vec_sphere(hit_info->hitpoint, sphere, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit_info->hitpoint));
	to_light = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
	angle = scalar_prod(to_camera, reflection);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, sphere->reflect_factor * 256);
	if (get_closest_hit_light(scene, ray) != NULL)
		angle = 0;
	factor = sphere->reflect_factor * 256 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor * scene->light->ratio);
	return (act_color);
}
t_vec3 get_reflection_vec_cylinder(t_vec3 hit_point, t_cylinder *cylinder, t_scene *scene)
{
	t_vec3 unit_normal_hit_point;
	t_vec3 b;
	t_vec3 reflection;
	t_vec3 to_light;

	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal_hit_point = unit_vec3(vec_sub(hit_point, cylinder->orig));
	b = vec_mult(unit_normal_hit_point, 2 * scalar_prod(unit_normal_hit_point, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_color get_specular_color_cylinder(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
    t_vec3 reflection;
    t_vec3 to_camera;
    t_vec3 to_light;
    float_t angle;
    float_t factor;
    t_cylinder *cylinder;
    t_color act_color;
    t_ray ray;

    ray.dir = vec_sub(scene->light->orig, hit_info->hitpoint);
    ray.orig = vec_add(hit_info->hitpoint, vec_mult(ray.dir, 0.01));
    cylinder = (t_cylinder *)object->content;
    to_light = unit_vec3(vec_sub(scene->light->orig, hit_info->hitpoint));
    reflection = vec_sub(vec_mult(hit_info->normal, 2 * scalar_prod(hit_info->normal, to_light)), to_light);
    to_camera = unit_vec3(vec_sub(scene->cam->orig, hit_info->hitpoint));
    angle = scalar_prod(to_camera, reflection);
    angle = clamp(angle, 0.0f, 1.0f);
    angle = pow(angle, cylinder->reflect_factor * 120);
    if (get_closest_hit_light(scene, ray) != NULL)
        angle = 0;
    factor = cylinder->reflect_factor * 128 / 256;
    act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor * scene->light->ratio);
    return (act_color);
}