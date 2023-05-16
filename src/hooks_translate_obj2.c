/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_obj2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:26 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:27 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_obj_dec_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y -= 0.1;
}

void	translate_obj_inc_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z += 0.1;
}

void	translate_obj_dec_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z -= 0.1;
}
