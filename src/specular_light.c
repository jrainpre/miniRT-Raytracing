#include "miniRT.h"

t_color	specular_light_obj(t_scene *scene, t_lst *object, t_hit_info *hit)
{
	t_object_type	type;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;

	type = object->type;
	if (type == SPHERE)
	{
		sphere = (t_sphere *)object->content;
		return (specular_light_sphere(scene, sphere, hit));
	}
	else if (type == PLANE)
	{
		plane = (t_plane *)object->content;
		return (specular_light_plane(scene, plane, hit));
	}
	else if (type == CYLINDER)
	{
		cylinder = (t_cylinder *)object->content;
		return (specular_light_cyl(scene, cylinder, hit));
	}
	return ((t_color){0, 0, 0, 0});
}

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

	ray.dir = vec_sub(scene->light->orig, hit->hitpoint);
	ray.orig = vec_add(hit->hitpoint, vec_mult(ray.dir, SHADOW_OFFSET));
	if (get_closest_hit_light(scene, ray) == NULL)
		return (1);
	return (0);
}

t_color	specular_light_plane(t_scene *scene, t_plane *plane, t_hit_info *hit)
{
	t_vec3	reflect;
	t_vec3	to_camera;
	float_t	angle;
	float_t	factor;
	t_color	act_color;

	reflect = unit_vec3(reflect_vec_plane(hit->hitpoint, plane, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit->hitpoint));
	angle = scalar_prod(to_camera, reflect);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, plane->reflect_factor * 120);
	if (check_in_shade(hit, scene) == 0)
		angle = 0;
	factor = plane->reflect_factor * 128 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor \
		* scene->light->ratio);
	return (act_color);
}

t_color	specular_light_sphere(t_scene *scene, t_sphere *sphere, t_hit_info *hit)
{
	t_vec3	reflect;
	t_vec3	to_camera;
	float_t	angle;
	float_t	factor;
	t_color	act_color;

	reflect = unit_vec3(reflect_vec_sphere(hit->hitpoint, sphere, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit->hitpoint));
	angle = scalar_prod(to_camera, reflect);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, sphere->reflect_factor * 256);
	if (check_in_shade(hit, scene) == 0)
		angle = 0;
	factor = sphere->reflect_factor * 256 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor \
		* scene->light->ratio);
	return (act_color);
}

t_color	specular_light_cyl(t_scene *scene, t_cylinder *cyl, t_hit_info *hit)
{
	t_vec3	reflect;
	t_vec3	to_camera;
	float_t	angle;
	float_t	factor;
	t_color	act_color;

	reflect = reflect_vec_cyl(hit, cyl, scene);
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit->hitpoint));
	angle = scalar_prod(to_camera, reflect);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, cyl->reflect_factor * 120);
	if (check_in_shade(hit, scene) == 0)
		angle = 0;
	factor = cyl->reflect_factor * 128 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, \
		angle * factor * scene->light->ratio);
	return (act_color);
}
