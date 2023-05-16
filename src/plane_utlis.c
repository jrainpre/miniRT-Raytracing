/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:14 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:15 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_values_plane(char ***param, char ***point, char ***normal_vec,
		char ***color)
{
	param = free_arr_null(*param);
	point = free_arr_null(*point);
	normal_vec = free_arr_null(*normal_vec);
	color = free_arr_null(*color);
}

int	split_parameter_plane(char *line, char ***param)
{
	*param = ft_split(line, ' ');
	if (*param == NULL)
		return (-1);
	return (0);
}

void	add_plane_list(t_lst_ref *objects, t_plane *plane)
{
	ft_add_lst_last(ft_lstnew(plane), objects);
	ft_lstlast(objects->head)->type = PLANE;
	ft_lstlast(objects->head)->is_slected = 0;
}
