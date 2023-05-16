/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_cylinder4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:15:59 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cy_state	cylinder_transition_15(t_cy_state state, char c)
{
	if (state == CY_REFLECTIVENESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_7);
		if (c == '.')
			return (CY_REFLECTIVENESS_DECIMAL);
		if (ft_isdigit(c))
			return (CY_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	else if (state == CY_SPACE_7)
	{
		if (c == ' ')
			return (CY_SPACE_7);
		if (ft_isdigit(c))
			return (CY_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '.')
			return (CY_REFLECTIVENESS_DECIMAL);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	return (cylinder_transition_16(state, c));
}

t_cy_state	cylinder_transition_16(t_cy_state state, char c)
{
	if (state == CY_REFLECTIVENESS_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_REFLECTIVENESS_AFTER_DECIMAL);
	}
	else if (state == CY_REFLECTIVENESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_7);
		if (ft_isdigit(c))
			return (CY_REFLECTIVENESS_AFTER_DECIMAL);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	else if (state == CY_ACCEPT)
		return (CY_ACCEPT);
	return (CY_REJECT);
}
