/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:41 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:16:42 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float_t	scalar_prod(t_vec3 vec1, t_vec3 vec2)
{
	float_t	prod;

	prod = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (prod);
}

t_vec3	cross_prod(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	prod;

	prod.x = vec1.y * vec2.z - vec1.z * vec2.y;
	prod.y = vec1.z * vec2.x - vec1.x * vec2.z;
	prod.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (prod);
}

float_t	vec_length(t_vec3 vec)
{
	float_t	length;

	length = sqrtf(scalar_prod(vec, vec));
	return (length);
}

t_vec3	unit_vec3(t_vec3 vec)
{
	t_vec3	unit;
	t_vec3	null_vec;

	null_vec = (t_vec3){0, 0, 0};
	if (vec_cmp(vec, null_vec) == 0)
		return (null_vec);
	unit = vec_div(vec, vec_length(vec));
	return (unit);
}

int	vec_cmp(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x != vec2.x)
		return (1);
	if (vec1.y != vec2.y)
		return (1);
	if (vec1.z != vec2.z)
		return (1);
	return (0);
}
