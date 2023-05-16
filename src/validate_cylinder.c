/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:08:36 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:09:06 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_cylinder(char *line)
{
	t_cy_state	state;
	int			i;

	i = 0;
	state = CY_START;
	while (line[i])
	{
		state = cylinder_transition(state, line[i]);
		if (state == CY_REJECT)
			break ;
		i++;
	}
	if (state == CY_ACCEPT || state == CY_BLUE || state == CY_SPACE_6
		|| state == CY_REFLECTIVENESS_AFTER_DECIMAL || state == CY_SPACE_5
		|| state == CY_REFLECTIVENESS_BEFORE_DECIMAL)
		return (1);
	ft_putstr_fd("Error\nCylinder could not be parsed\n", STDERR_FILENO);
	return (0);
}
