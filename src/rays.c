/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:41 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:42 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pt3	ray_point_at(t_ray ray, float_t t)
{
	t_pt3	point;

	point = vec_add(ray.orig, vec_mult(ray.dir, t));
	return (point);
}
