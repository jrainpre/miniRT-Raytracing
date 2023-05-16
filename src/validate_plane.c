/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:15:16 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 15:16:03 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_plane(char *line)
{
	t_p_state	state;
	int			i;

	i = 0;
	state = P_START;
	while (line[i])
	{
		state = plane_transition(state, line[i]);
		if (state == P_REJECT)
			break ;
		i++;
	}
	if (state == P_ACCEPT || state == P_BLUE || state == P_SPACE_4
		|| state == P_REFLECTIVENESS_AFTER_DECIMAL
		|| state == P_REFLECTIVENESS_BEFORE_DECIMAL || state == P_SPACE_5)
		return (1);
	ft_putstr_fd("Error\nPlane could not be parsed\n", STDERR_FILENO);
	return (0);
}
