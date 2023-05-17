/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:13:40 by frafal            #+#    #+#             */
/*   Updated: 2023/05/17 13:49:13 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_cam_light(t_scene *scene, t_lst *runner, t_resolution win, char *line)
{
	if (runner->type == CAMERA)
	{
		scene->cam = init_camera(win, line);
		if (scene->cam == NULL)
			return (-1);
	}
	else if (runner->type == LIGHT)
	{
		scene->light = init_light(line);
		if (scene->light == NULL)
			return (-1);
	}
	else if (runner->type == AMBIENT_LIGHT)
	{
		scene->ambient_light = init_ambient_light(line);
		if (scene->ambient_light == NULL)
			return (-1);
	}
	return (0);
}

int	fill_obj(t_scene *scene, t_lst *runner, t_resolution win, char *line)
{
	(void)win;
	if (runner->type == SPHERE)
	{
		if (add_sphere(scene->objects, line) == -1)
			return (-1);
	}
	else if (runner->type == PLANE)
	{
		if (add_plane(scene->objects, line) == -1)
			return (-1);
	}
	else if (runner->type == CYLINDER)
	{
		if (add_cylinder(scene->objects, line) == -1)
			return (-1);
	}
	return (0);
}

int	fill_scene(t_scene *scene, t_lst_ref *scene_lines, t_resolution win)
{
	char	*line;
	t_lst	*runner;

	runner = scene_lines->head;
	while (runner)
	{
		line = (char *)runner->content;
		if (fill_cam_light(scene, runner, win, line) == -1)
			return (-1);
		else if (fill_obj(scene, runner, win, line) == -1)
			return (-1);
		runner = runner->next;
	}
	return (1);
}

float_t	get_reflect_factor_from_str(char *str)
{
	float_t	reflect_factor;

	if (str == NULL)
		return (0);
	reflect_factor = ft_atof(str);
	if (reflect_factor < 0 || reflect_factor > 1)
		return (0);
	return (reflect_factor);
}
