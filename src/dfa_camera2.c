/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_camera2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:59:19 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_c_state	camera_transition_5(t_c_state state, char c)
{
	if (state == C_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == C_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (ft_isdigit(c))
			return (C_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == C_SPACE_2)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIENTATION_X_SIGN);
	}
	return (camera_transition_6(state, c));
}

t_c_state	camera_transition_6(t_c_state state, char c)
{
	if (state == C_ORIENTATION_X_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIENTATION_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_3);
		if (c == '.')
			return (C_ORIENTATION_X_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIENTATION_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_AFTER_DECIMAL);
	}
	return (camera_transition_7(state, c));
}

t_c_state	camera_transition_7(t_c_state state, char c)
{
	if (state == C_ORIENTATION_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_3);
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_AFTER_DECIMAL);
	}
	else if (state == C_COMMA_3)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIENTATION_Y_SIGN);
	}
	else if (state == C_ORIENTATION_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Y_BEFORE_DECIMAL);
	}
	return (camera_transition_8(state, c));
}

t_c_state	camera_transition_8(t_c_state state, char c)
{
	if (state == C_ORIENTATION_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_4);
		if (c == '.')
			return (C_ORIENTATION_Y_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIENTATION_Y_BEFORE_DECIMAL);
	}
	else if (state == C_ORIENTATION_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Y_AFTER_DECIMAL);
	}
	else if (state == C_ORIENTATION_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_4);
		if (ft_isdigit(c))
			return (C_ORIENTATION_Y_AFTER_DECIMAL);
	}
	return (camera_transition_9(state, c));
}

t_c_state	camera_transition_9(t_c_state state, char c)
{
	if (state == C_COMMA_4)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIENTATION_Z_SIGN);
	}
	else if (state == C_ORIENTATION_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIENTATION_Z_BEFORE_DECIMAL);
	}
	else if (state == C_ORIENTATION_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_3);
		if (c == '.')
			return (C_ORIENTATION_Z_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIENTATION_Z_BEFORE_DECIMAL);
	}
	return (camera_transition_10(state, c));
}
