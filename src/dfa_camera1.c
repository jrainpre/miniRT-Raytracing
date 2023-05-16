/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_camera1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:59:24 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_c_state	camera_transition(t_c_state state, char c)
{
	if (state == C_START)
	{
		if (c == ' ')
			return (C_START);
		if (c == 'C')
			return (C_IDENTIFIER_1);
	}
	else if (state == C_IDENTIFIER_1)
	{
		if (c == ' ')
			return (C_SPACE_1);
	}
	else if (state == C_SPACE_1)
	{
		if (c == ' ')
			return (C_SPACE_1);
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_X_SIGN);
	}
	return (camera_transition_1(state, c));
}

t_c_state	camera_transition_1(t_c_state state, char c)
{
	if (state == C_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_1);
		if (c == '.')
			return (C_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_X_AFTER_DECIMAL);
	}
	return (camera_transition_2(state, c));
}

t_c_state	camera_transition_2(t_c_state state, char c)
{
	if (state == C_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_1);
		if (ft_isdigit(c))
			return (C_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == C_COMMA_1)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_Y_SIGN);
	}
	else if (state == C_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
	}
	return (camera_transition_3(state, c));
}

t_c_state	camera_transition_3(t_c_state state, char c)
{
	if (state == C_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_2);
		if (c == '.')
			return (C_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == C_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_2);
		if (ft_isdigit(c))
			return (C_ORIG_Y_AFTER_DECIMAL);
	}
	return (camera_transition_4(state, c));
}

t_c_state	camera_transition_4(t_c_state state, char c)
{
	if (state == C_COMMA_2)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_Z_SIGN);
	}
	else if (state == C_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (c == '.')
			return (C_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
	}
	return (camera_transition_5(state, c));
}
