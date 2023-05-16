/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_camera3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:58:26 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_c_state	camera_transition_10(t_c_state state, char c)
{
	if (state == C_ORIENTATION_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Z_AFTER_DECIMAL);
	}
	else if (state == C_ORIENTATION_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_3);
		if (ft_isdigit(c))
			return (C_ORIENTATION_Z_AFTER_DECIMAL);
	}
	else if (state == C_SPACE_3)
	{
		if (c == ' ')
			return (C_SPACE_3);
		if (ft_isdigit(c))
			return (C_FOV_BEFORE_DECIMAL);
	}
	return (camera_transition_11(state, c));
}

t_c_state	camera_transition_11(t_c_state state, char c)
{
	if (state == C_FOV_BEFORE_DECIMAL)
	{
		if (c == '.')
			return (C_FOV_DECIMAL);
		if (ft_isdigit(c))
			return (C_FOV_BEFORE_DECIMAL);
		if (c == ' ')
			return (C_SPACE_4);
		if (c == '\n')
			return (C_ACCEPT);
	}
	else if (state == C_FOV_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_FOV_AFTER_DECIMAL);
	}
	else if (state == C_FOV_AFTER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_FOV_AFTER_DECIMAL);
		if (c == ' ')
			return (C_SPACE_4);
	}
	return (camera_transition_12(state, c));
}

t_c_state	camera_transition_12(t_c_state state, char c)
{
	if (state == C_SPACE_4)
	{
		if (c == ' ')
			return (C_SPACE_4);
		if (c == '\n')
			return (C_ACCEPT);
	}
	else if (state == C_ACCEPT)
		return (C_ACCEPT);
	return (C_REJECT);
}
