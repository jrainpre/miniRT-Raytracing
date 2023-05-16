/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_obj1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:08 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:09 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotate_obj_inc_x(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_x(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_x(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_dec_x(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_x(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_x(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_inc_y(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_y(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_y(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}
