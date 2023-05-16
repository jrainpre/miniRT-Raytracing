/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_obj2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:12 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:13 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotate_obj_dec_y(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_y(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_y(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_inc_z(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_z(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_z(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_dec_z(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_z(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_z(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}
