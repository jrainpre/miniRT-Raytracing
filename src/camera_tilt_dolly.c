/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_tilt_dolly.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:12:39 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:12:40 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	tilt_down(t_camera *cam, float_t angle)
{
	rotate_camera_around_left_axis(cam, angle);
}

void	tilt_up(t_camera *cam, float_t angle)
{
	rotate_camera_around_left_axis(cam, -angle);
}

void	dolly_in(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->orientation, meters));
}

void	dolly_out(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->orientation, -meters));
}
