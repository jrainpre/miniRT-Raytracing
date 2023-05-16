/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_obj1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:22 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_obj_inc_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x += 0.1;
}

void	translate_obj_dec_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x -= 0.1;
}

void	translate_obj_inc_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y += 0.1;
}
