/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:47:26 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:01:59 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_camera(char *line)
{
	t_c_state	state;
	int			i;

	i = 0;
	state = C_START;
	while (line[i])
	{
		state = camera_transition(state, line[i]);
		if (state == CY_REJECT)
			break ;
		i++;
	}
	if (state == C_ACCEPT || state == C_FOV_AFTER_DECIMAL
		|| state == C_FOV_BEFORE_DECIMAL || state == C_SPACE_4)
		return (1);
	ft_putstr_fd("Error\nCamera could not be parsed\n", STDERR_FILENO);
	return (0);
}
