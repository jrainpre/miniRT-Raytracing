/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:30 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:14:31 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	loop_hook(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_scene(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	return (0);
}

int	key_hook1(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_app(data);
	if (keysym == XK_n)
		select_next_object(data);
	if (keysym == XK_m && data->slected_obj != NULL)
	{
		data->slected_obj->is_slected = 0;
		data->slected_obj = NULL;
	}
	if (data->slected_obj != NULL)
		object_actions(keysym, data);
	else
		scene_actions(keysym, data);
	data->pixelcolors_int = 1;
	ft_memset(data->pixelcolors, 0, data->win.width * data->win.height
		* sizeof(t_color));
	return (0);
}

int	close_app(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	data = free_data_null(data);
	exit(0);
	return (0);
}

void	init_pixelcolors(t_data *data)
{
	data->pixelcolors = calloc_or_print_error(data->win.width * \
		data->win.height, sizeof(t_color));
	data->pixelcolors_int = 1;
}

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_putstr_fd("Failed to set up the connection to the X server\n", 2);
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width,
			data->win.height, "miniRT");
	if (data->win_ptr == NULL)
		ft_putstr_fd("Failed to create a new window\n", 2);
	if (data->win_ptr == NULL)
		return (-1);
	data->img = malloc_or_print_error(sizeof(t_img));
	init_pixelcolors(data);
	if (data->img == NULL || data->pixelcolors == NULL)
		return (-1);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->win.width,
			data->win.height);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, close_app, data);
	mlx_hook(data->win_ptr, KeyPress, 1, key_hook1, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
