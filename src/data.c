/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:13:16 by frafal            #+#    #+#             */
/*   Updated: 2023/05/17 10:26:59 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc_or_print_error(sizeof (t_data));
	if (data == NULL)
		return (NULL);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->scene = NULL;
	data->scene_lines = NULL;
	data->img = NULL;
	data->pixelcolors = NULL;
	data->win = (t_resolution){720, 720};
	data->slected_obj = NULL;
	return (data);
}

void	*free_data_null(t_data *data)
{
	data->mlx_ptr = free_null(data->mlx_ptr);
	data->img = free_null(data->img);
	data->scene = free_scene_null(data->scene);
	data->scene_lines = free_lst_null(data->scene_lines);
	data->pixelcolors = free_null(data->pixelcolors);
	data = free_null(data);
	return (data);
}
