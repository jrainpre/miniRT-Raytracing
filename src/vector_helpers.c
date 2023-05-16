/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:24 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:16:25 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	get_vec_from_str_arr(char **str)
{
	t_vec3	vec;

	vec.x = ft_atof(str[0]);
	vec.y = ft_atof(str[1]);
	vec.z = ft_atof(str[2]);
	return (vec);
}
