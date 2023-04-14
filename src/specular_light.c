#include "miniRT.h"

t_color get_specular_color_object(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_specular_color_sphere(scene, object, hitpoint));
	// else if (type == PLANE)
	// 	return (get_specular_light_plane(scene, object, hitpoint, ray));
	// else if (type == CYLINDER)
	// 	return (get_specular_light_cylinder(scene, object, hitpoint, ray));
	return ((t_color){0, 0, 0, 0});
}

t_vec3 get_reflection_vec_sphere(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3 unit_normal_hit_point;
	t_vec3 b;
	t_vec3 reflection;
	t_vec3 to_light;

	//R = 2*n*dot_product(n,L) - L   // When L goes from the vertex to the light source
	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal_hit_point = unit_vec3(vec_sub(hit_point, sphere->orig));
	b = vec_mult(unit_normal_hit_point, 2 * scalar_prod(unit_normal_hit_point, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_color get_specular_color_sphere(t_scene *scene, t_lst *object, t_vec3 hitpoint)
{
	t_vec3 reflection;
	t_vec3 to_camera;
	t_vec3 to_light;
	float_t angle;
	float_t factor;
	t_sphere *sphere;
	t_color act_color;

	sphere = (t_sphere *)object->content;
	reflection = unit_vec3(get_reflection_vec_sphere(hitpoint, sphere, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hitpoint));
	to_light = unit_vec3(vec_sub(scene->light->orig, hitpoint));
	angle = scalar_prod(to_camera, reflection);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, sphere->reflect_factor * 90);
	factor = sphere->reflect_factor * 128 / 256;
	act_color = color_mult((t_color){1.0, 1.0, 1.0, 1.0}, angle * factor * scene->light->ratio);
	return (act_color);
}