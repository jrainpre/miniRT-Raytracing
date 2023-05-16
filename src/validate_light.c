/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:51:26 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:51:31 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_light(char *line)
{
	t_l_state	state;
	int			i;

	i = 0;
	state = L_START;
	while (line[i])
	{
		state = light_transition(state, line[i]);
		if (state == L_REJECT)
			break ;
		i++;
	}
	if (state == L_ACCEPT || state == L_SPACE_4 || state == L_BLUE)
		return (1);
	ft_putstr_fd("Error\nLight could not be parsed\n", STDERR_FILENO);
	return (0);
}
