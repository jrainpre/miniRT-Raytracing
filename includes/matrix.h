/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:45:22 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:45:23 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <math.h>

typedef struct s_mat3x3
{
	float_t		c1r1;
	float_t		c2r1;
	float_t		c3r1;
	float_t		c1r2;
	float_t		c2r2;
	float_t		c3r2;
	float_t		c1r3;
	float_t		c2r3;
	float_t		c3r3;
}			t_mat3x3;	

#endif
