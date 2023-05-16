/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_pan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:12:29 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:12:30 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pan_left(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, angle);
}

void	pan_right(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, -angle);
}
