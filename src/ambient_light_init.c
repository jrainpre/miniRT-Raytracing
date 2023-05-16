/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:11:45 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:11:46 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	**split_parameters_ambient(char *line, char ***color)
{
	char	**parameters;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (NULL);
	*color = ft_split(parameters[2], ',');
	if (*color == NULL)
	{
		parameters = free_arr_null(parameters);
		return (NULL);
	}
	return (parameters);
}

t_ambient_light	*validate_and_assign_ambient(t_ambient_light *ambient, \
	char **param, char **color)
{
	ambient->ratio = ft_atof(param[1]);
	if (!is_valid_ratio(ambient->ratio))
	{
		ambient = free_null(ambient);
		param = free_arr_null(param);
		color = free_arr_null(color);
		return (NULL);
	}
	ambient->color = get_color_from_str_arr(color);
	if (!is_valid_color(ambient->color))
	{
		ambient = free_null(ambient);
		param = free_arr_null(param);
		color = free_arr_null(color);
		return (NULL);
	}
	return (ambient);
}

t_ambient_light	*init_ambient_light(char *line)
{
	t_ambient_light	*ambient;
	char			**param;
	char			**color;

	param = split_parameters_ambient(line, &color);
	if (param == NULL)
		return (NULL);
	ambient = malloc_or_print_error(sizeof(t_ambient_light));
	if (ambient == NULL)
		return (NULL);
	ambient = validate_and_assign_ambient(ambient, param, color);
	if (ambient == NULL)
		return (NULL);
	param = free_arr_null(param);
	color = free_arr_null(color);
	return (ambient);
}
