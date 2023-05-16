/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:13:08 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:13:09 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_normal_cylinder(t_hit_info *hit_info, t_cylinder *cylinder)
{
	normal_cyl_proj(hit_info, cylinder);
	normal_cyl_top_cap(hit_info, cylinder);
	normal_cyl_bottom_cap(hit_info, cylinder);
}

void	normal_cyl_proj(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	projection;
	t_vec3	projected_point;
	t_lst	object;
	float_t	distance_t;
	t_vec3	temp;

	temp = vec_sub(hit_info->hitpoint, cylinder->orig);
	projection = scalar_prod(temp, cylinder->axis);
	distance_t = get_cyl_distance_t_proj(cylinder, hit_info->ray, hit_info);
	if (fabs(hit_info->distance - distance_t) < 0.001)
	{
		temp = vec_mult(cylinder->axis, projection);
		projected_point = vec_add(cylinder->orig, temp);
		hit_info->normal = vec_sub(hit_info->hitpoint, projected_point);
		hit_info->normal = unit_vec3(hit_info->normal);
	}
}

void	normal_cyl_top_cap(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	distance_t;

	distance_t = find_top_cap_intersection(cylinder, hit_info->ray);
	if (fabs(hit_info->distance - distance_t) < 0.001)
	{
		hit_info->normal = cylinder->axis;
		hit_info->is_inside_hit = 0;
	}
}

void	normal_cyl_bottom_cap(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	distance_t;

	distance_t = find_bottom_cap_intersection(cylinder, hit_info->ray);
	if (fabs(hit_info->distance - distance_t) < 0.001)
	{
		hit_info->normal = vec_mult(cylinder->axis, -1);
		hit_info->is_inside_hit = 0;
	}
}
