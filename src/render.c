/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:00 by frafal            #+#    #+#             */
/*   Updated: 2023/06/30 09:47:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	t_img	*img;

	img = data->img;
	if (x < 0 || x >= data->win.width || y < 0 || y >= data->win.height)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = color;
}

t_ray	get_ray_offset(t_camera *cam, float_t u, float_t v)
{
	t_ray	ray;
	t_vec3	fuzz;

	ray.orig = cam->orig;
	ray.dir = vec_sub(vec_add(vec_add(vec_mult(cam->horizontal, u), \
		vec_mult(cam->vertical, v)), cam->upper_left_corner), cam->orig);
	fuzz = vec_mult(random_in_unit_sphere(), FUZZ_FACTOR);
	ray.dir = vec_add(ray.dir, fuzz);
	return (ray);
}

int	mult_sample_color(t_data *data, t_color color, int i, int j)
{
	data->pixelcolors[j * data->win.width + i] = \
		color_add(data->pixelcolors[j * data->win.width + i], color);
	color = color_div(data->pixelcolors[j * data->win.width + i], \
		data->pixelcolors_int);
	color = color_clamp(color, 0.0f, 1.0f);
	return (color_conversion(color));
}

void	render_scene(t_data *data)
{
	t_ray		ray;
	t_it		it;
	t_color		act_color;
	int			color;

	it.j = 0;
	while (it.j < data->win.height)
	{
		it.i = 0;
		while (it.i < data->win.width)
		{
			it.u = (float_t)it.i / (data->win.width - 1);
			it.v = (float_t)it.j / (data->win.height - 1);
			ray = get_ray_offset(data->scene->cam, it.u, it.v);
			act_color = follow_ray(data->scene, ray);
			color = mult_sample_color(data, act_color, it.i, it.j);
			img_pix_put(data, it.i, it.j, color);
			it.i++;
		}
		it.j++;
	}
	data->pixelcolors_int++;
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->win.height)
	{
		i = 0;
		while (i < data->win.width)
		{
			img_pix_put(data, i, j, color);
			i++;
		}
		j++;
	}
}
