/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_sphere3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:02:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:08:02 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_s_state	sphere_transition_10(t_s_state state, char c)
{
	if (state == S_SPACE_5)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '.')
			return (S_REFLECTIVENESS_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_REFLECTIVENESS_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_AFTER_DECIMAL);
	}
	return (sphere_transition_11(state, c));
}

t_s_state	sphere_transition_11(t_s_state state, char c)
{
	if (state == S_REFLECTIVENESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_AFTER_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_ACCEPT)
		return (S_ACCEPT);
	return (S_REJECT);
}
