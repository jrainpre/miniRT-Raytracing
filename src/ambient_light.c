/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:11:51 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:11:52 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ambient_light_obj(t_scene *scene, t_lst *object)
{
	t_object_type	type;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;

	type = object->type;
	if (type == SPHERE)
	{
		sphere = (t_sphere *)object->content;
		return (ambient_light_sphere(scene, sphere));
	}
	else if (type == PLANE)
	{
		plane = (t_plane *)object->content;
		return (ambient_light_plane(scene, plane));
	}
	else if (type == CYLINDER)
	{
		cylinder = (t_cylinder *)object->content;
		return (ambient_light_cylinder(scene, cylinder));
	}
	return ((t_color){0, 0, 0, 0});
}

t_color	ambient_light_sphere(t_scene *scene, t_sphere *sphere)
{
	t_color	ambient;

	ambient = color_mult_color(sphere->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}

t_color	ambient_light_plane(t_scene *scene, t_plane *plane)
{
	t_color	ambient;

	ambient = color_mult_color(plane->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}

t_color	ambient_light_cylinder(t_scene *scene, t_cylinder *cyl)
{
	t_color	ambient;

	ambient = color_mult_color(cyl->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	return (ambient);
}
