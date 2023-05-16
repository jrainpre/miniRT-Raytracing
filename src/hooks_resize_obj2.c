/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_resize_obj2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:05 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:06 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	decrease_hight_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	if (cylinder->height > 0.1)
		cylinder->height -= 0.1;
}

void	object_resize_up(t_lst *object)
{
	if (object->type == SPHERE)
		increase_diameter_sphere(object->content);
	if (object->type == CYLINDER)
		increase_diameter_cylinder(object->content);
}

void	object_resize_down(t_lst *object)
{
	if (object->type == SPHERE)
		decrease_diameter_sphere(object->content);
	if (object->type == CYLINDER)
		decrease_diameter_cylinder(object->content);
}

void	object_resize_left(t_lst *object)
{
	if (object->type == CYLINDER)
		increase_hight_cylinder(object->content);
}

void	object_resize_right(t_lst *object)
{
	if (object->type == CYLINDER)
		decrease_hight_cylinder(object->content);
}
