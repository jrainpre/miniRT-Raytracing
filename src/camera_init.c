/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:11:59 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:12:05 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	**split_parameter_camera(char *line, char ***orig, char ***orientation)
{
	char	**param;

	param = ft_split(line, ' ');
	if (param == NULL)
		return (NULL);
	*orig = ft_split(param[1], ',');
	if (*orig == NULL)
	{
		param = free_arr_null(param);
		return (NULL);
	}
	*orientation = ft_split(param[2], ',');
	if (*orientation == NULL)
	{
		param = free_arr_null(param);
		*orig = free_arr_null(*orig);
		return (NULL);
	}
	return (param);
}

t_camera	*validate_and_assign_camera(t_camera *cam, char **param, \
	char **orig, char **orientation)
{
	cam->orig = get_vec_from_str_arr(orig);
	cam->orientation = get_vec_from_str_arr(orientation);
	if (!is_normalized(cam->orientation))
	{
		cam = free_null(cam);
		param = free_arr_null(param);
		orig = free_arr_null(orig);
		orientation = free_arr_null(orientation);
		return (NULL);
	}
	return (cam);
}

void	init_camera_properties(t_camera *cam, t_resolution win, \
	char **parameters)
{
	cam->fov = ft_atof(parameters[3]);
	if (cam->fov < 1)
		cam->fov = 1;
	if (cam->fov > 180)
		cam->fov = 180;
	cam->sensor_height = 0.024;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) \
		* cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) \
		/ tanf(deg_to_rad(cam->fov / 2.0));
	if (cam->orientation.y == 1 || cam->orientation.y == -1)
		cam->horizontal = (t_vec3){1, 0, 0};
	else
		cam->horizontal = cross_prod(cam->orientation, (t_vec3){0, 1, 0});
	cam->horizontal = unit_vec3(cam->horizontal);
	cam->left = vec_mult(cam->horizontal, -1);
	cam->vertical = cross_prod(cam->orientation, cam->horizontal);
	cam->vertical = unit_vec3(cam->vertical);
	cam->up = vec_mult(cam->vertical, -1);
	cam->horizontal = vec_mult(cam->horizontal, cam->sensor_width);
	cam->vertical = vec_mult(cam->vertical, cam->sensor_height);
	cam->upper_left_corner = calc_upper_left_corner(cam);
}

t_camera	*init_camera(t_resolution win, char *line)
{
	t_camera	*cam;
	char		**param;
	char		**orig;
	char		**orientation;

	param = split_parameter_camera(line, &orig, &orientation);
	if (param == NULL)
		return (NULL);
	cam = malloc_or_print_error(sizeof(t_camera));
	if (cam == NULL)
		return (NULL);
	cam = validate_and_assign_camera(cam, param, orig, orientation);
	if (cam == NULL)
		return (NULL);
	init_camera_properties(cam, win, param);
	param = free_arr_null(param);
	orig = free_arr_null(orig);
	orientation = free_arr_null(orientation);
	return (cam);
}

t_vec3	calc_upper_left_corner(t_camera *cam)
{
	t_vec3	upper_left;
	t_vec3	mid;
	t_vec3	flipped_half_h;
	t_vec3	flipped_half_v;

	mid = vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length));
	flipped_half_h = vec_div(cam->horizontal, -2);
	flipped_half_v = vec_div(cam->vertical, -2);
	upper_left = vec_add(flipped_half_h, flipped_half_v);
	return (vec_add(mid, upper_left));
}
