/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:12:34 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:12:35 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotate_y_camera(t_camera *cam, float_t angle)
{
	cam->orientation = rotate_y(cam->orientation, angle);
	cam->left = rotate_y(cam->left, angle);
	cam->up = rotate_y(cam->up, angle);
	cam->horizontal = rotate_y(cam->horizontal, angle);
	cam->vertical = rotate_y(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
}

void	rotate_x_camera(t_camera *cam, float_t angle)
{
	cam->orientation = rotate_x(cam->orientation, angle);
	cam->left = rotate_x(cam->left, angle);
	cam->up = rotate_x(cam->up, angle);
	cam->horizontal = rotate_x(cam->horizontal, angle);
	cam->vertical = rotate_x(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
}

void	rotate_camera_around_left_axis(t_camera *cam, float_t angle)
{
	t_mat3x3	old_state;
	t_mat3x3	new_state;

	old_state = (t_mat3x3){
		cam->left.x, cam->up.x, cam->orientation.x, cam->left.y, cam->up.y,
		cam->orientation.y, cam->left.z, cam->up.z, cam->orientation.z};
	new_state = mat3x3_dot_prod(old_state, get_rot_x(angle));
	cam->orientation = mat_mult(new_state, (t_vec3){0, 0, 1});
	cam->left = mat_mult(new_state, (t_vec3){1, 0, 0});
	cam->up = mat_mult(new_state, (t_vec3){0, 1, 0});
	cam->vertical = mat_mult(new_state, (t_vec3){0, -cam->sensor_height, 0});
	cam->horizontal = mat_mult(new_state, (t_vec3){-cam->sensor_width, 0, 0});
	cam->upper_left_corner = calc_upper_left_corner(cam);
}
