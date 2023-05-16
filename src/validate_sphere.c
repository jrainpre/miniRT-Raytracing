/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:08:45 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:09:05 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_sphere(char *line)
{
	t_s_state	state;
	int			i;

	i = 0;
	state = S_START;
	while (line[i])
	{
		state = sphere_transition(state, line[i]);
		if (state == S_REJECT)
			break ;
		i++;
	}
	if (state == S_ACCEPT || state == S_SPACE_4 || state == S_BLUE
		|| state == S_REFLECTIVENESS_AFTER_DECIMAL || state == S_SPACE_5
		|| state == S_REFLECTIVENESS_BEFORE_DECIMAL)
		return (1);
	ft_putstr_fd("Error\nSphere could not be parsed\n", STDERR_FILENO);
	return (0);
}
