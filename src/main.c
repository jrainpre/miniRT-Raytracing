/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:14:48 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:34:20 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_errors(t_data *data, int argc, char **argv)
{
	if (argc == 4)
		data->win = (t_resolution){ft_atoi(argv[2]), ft_atoi(argv[3])};
	data->scene_lines = read_file(argv[1]);
	if (data->scene_lines == NULL)
	{
		data = free_data_null(data);
		return (-1);
	}
	if (!is_valid_scene(data->scene_lines))
	{
		data = free_data_null(data);
		return (-1);
	}
	return (0);
}

int	init_and_fill_scene(t_data *data)
{
	data->scene = init_scene();
	if (data->scene == NULL)
	{
		data->scene = free_scene_null(data->scene);
		data = free_data_null(data);
		return (-1);
	}
	if (fill_scene(data->scene, data->scene_lines, data->win) == -1)
	{
		data->scene = free_scene_null(data->scene);
		data = free_data_null(data);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!arguments_valid(argc, argv))
		return (1);
	data = init_data();
	if (data == NULL)
		return (1);
	if (check_errors(data, argc, argv) == -1)
		return (1);
	if (init_and_fill_scene(data) == -1)
		return (1);
	if (start_mlx(data) == -1)
	{
		data = free_data_null(data);
		return (-1);
	}
	return (0);
}
