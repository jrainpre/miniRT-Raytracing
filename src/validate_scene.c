/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:13:26 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 19:13:02 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_scene(t_lst_ref *scene_lines)
{
	t_line_state	state;
	t_lst			*runner;
	char			*line;
	t_item_numbers	items;

	items = (t_item_numbers){0, 0, 0, 0};
	runner = scene_lines->head;
	while (runner)
	{
		line = (char *)runner->content;
		runner->type = NOT_VALID;
		state = LINE_START;
		if (!is_valid_line(line, runner, state, &items))
			return (0);
		runner = runner->next;
	}
	if (!valid_number_of_items(items))
		return (0);
	return (1);
}

int	valid_number_of_items(t_item_numbers items)
{
	if (items.cameras != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one camera\n", STDERR_FILENO);
		return (0);
	}
	if (items.lights != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one light\n", STDERR_FILENO);
		return (0);
	}
	if (items.ambient_lights != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one ambient light\n", STDERR_FILENO);
		return (0);
	}
	if (items.objects < 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected at least one object\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
