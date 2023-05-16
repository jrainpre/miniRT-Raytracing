/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:56 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float_t	get_plane_distance_t(t_lst *object, t_ray ray)
{
	t_plane_hit_calc	calc;	
	t_vec3				ray_plane_diff;
	t_plane				*plane;
	float_t				dir_len;

	plane = (t_plane *)object->content;
	calc.denominator = scalar_prod(unit_vec3(ray.dir), plane->normal_vec);
	dir_len = vec_length(ray.dir);
	if (calc.denominator > FLT_EPSILON)
	{
		ray_plane_diff = vec_sub(plane->point, ray.orig);
		calc.numerator = scalar_prod(ray_plane_diff, plane->normal_vec);
		calc.distance_t = calc.numerator / calc.denominator;
		calc.distance_t /= dir_len;
		if (calc.distance_t >= 0)
			return (calc.distance_t);
	}
	return (-1);
}
