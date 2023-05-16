/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient_light.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:39:07 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:39:09 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_ambient_light(char *line)
{
	t_a_state	state;
	int			i;

	i = 0;
	state = A_START;
	while (line[i])
	{
		state = ambient_light_transition(state, line[i]);
		if (state == A_REJECT)
			break ;
		i++;
	}
	if (state == A_ACCEPT || state == A_BLUE || state == A_SPACE_3)
		return (1);
	ft_putstr_fd("Error\nAmbient light could not be parsed\n", STDERR_FILENO);
	return (0);
}
