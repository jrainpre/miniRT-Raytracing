/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:14 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:16:15 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
