/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:12:04 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 22:59:13 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_line_state	line_transition(t_line_state state, char c)
{
	if (state == LINE_START)
	{
		if (c == ' ')
			return (LINE_START);
		if (c == '\n')
			return (LINE_NEW_LINE);
		if (c == 'A')
			return (LINE_AMBIENT_LIGHT);
		if (c == 'C')
			return (LINE_CAMERA);
		if (c == 'L')
			return (LINE_LIGHT);
		if (c == 's')
			return (LINE_SPHERE);
		if (c == 'p')
			return (LINE_PLANE);
		if (c == 'c')
			return (LINE_CYLINDER);
	}
	return (LINE_REJECT);
}

int	is_valid_line(char *line, t_lst *runner,
	t_line_state state, t_item_numbers *items)
{
	while (*line)
	{
		state = line_transition(state, *line);
		if (state == LINE_REJECT)
		{
			ft_putstr_fd("Error\nInvalid Line\n", STDERR_FILENO);
			return (0);
		}
		else if (state == LINE_NEW_LINE)
			return (1);
		else if (state != LINE_START)
			break ;
		line++;
	}
	if (state == LINE_AMBIENT_LIGHT)
	{
		items->ambient_lights++;
		runner->type = AMBIENT_LIGHT;
		if (!is_valid_ambient_light(line))
			return (0);
	}
	return (is_valid_line_1(line, runner, state, items));
}

int	is_valid_line_1(char *line, t_lst *runner,
	t_line_state state, t_item_numbers *items)
{
	if (state == LINE_CAMERA)
	{
		items->cameras++;
		runner->type = CAMERA;
		if (!is_valid_camera(line))
			return (0);
	}
	else if (state == LINE_LIGHT)
	{
		items->lights++;
		runner->type = LIGHT;
		if (!is_valid_light(line))
			return (0);
	}
	else if (state == LINE_SPHERE)
	{
		items->objects++;
		runner->type = SPHERE;
		if (!is_valid_sphere(line))
			return (0);
	}
	return (is_valid_line_2(line, runner, state, items));
}

int	is_valid_line_2(char *line, t_lst *runner,
	t_line_state state, t_item_numbers *items)
{
	if (state == LINE_PLANE)
	{
		items->objects++;
		runner->type = PLANE;
		if (!is_valid_plane(line))
			return (0);
	}
	else if (state == LINE_CYLINDER)
	{
		items->objects++;
		runner->type = CYLINDER;
		if (!is_valid_cylinder(line))
			return (0);
	}
	return (1);
}
