/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:07 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:09 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	mat_mult(t_mat3x3 mat, t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x * mat.c1r1 + vec.y * mat.c2r1 + vec.z * mat.c3r1;
	res.y = vec.x * mat.c1r2 + vec.y * mat.c2r2 + vec.z * mat.c3r2;
	res.z = vec.x * mat.c1r3 + vec.y * mat.c2r3 + vec.z * mat.c3r3;
	return (res);
}

t_mat3x3	mat3x3_dot_prod(t_mat3x3 a, t_mat3x3 b)
{
	t_mat3x3	res;

	res.c1r1 = b.c1r1 * a.c1r1 + b.c1r2 * a.c2r1 + b.c1r3 * a.c3r1;
	res.c1r2 = b.c1r1 * a.c1r2 + b.c1r2 * a.c2r2 + b.c1r3 * a.c3r2;
	res.c1r3 = b.c1r1 * a.c1r3 + b.c1r2 * a.c2r3 + b.c1r3 * a.c3r3;
	res.c2r1 = b.c2r1 * a.c1r1 + b.c2r2 * a.c2r1 + b.c2r3 * a.c3r1;
	res.c2r2 = b.c2r1 * a.c1r2 + b.c2r2 * a.c2r2 + b.c2r3 * a.c3r2;
	res.c2r3 = b.c2r1 * a.c1r3 + b.c2r2 * a.c2r3 + b.c2r3 * a.c3r3;
	res.c3r1 = b.c3r1 * a.c1r1 + b.c3r2 * a.c2r1 + b.c3r3 * a.c3r1;
	res.c3r2 = b.c3r1 * a.c1r2 + b.c3r2 * a.c2r2 + b.c3r3 * a.c3r2;
	res.c3r3 = b.c3r1 * a.c1r3 + b.c3r2 * a.c2r3 + b.c3r3 * a.c3r3;
	return (res);
}
