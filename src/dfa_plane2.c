/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_plane2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 15:13:02 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_p_state	plane_transition_5(t_p_state state, char c)
{
	if (state == P_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (ft_isdigit(c))
			return (P_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == P_SPACE_2)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (ft_isdigit(c))
			return (P_NORMAL_X_BEFORE_DECIMAL);
		if (c == '-')
			return (P_NORMAL_X_SIGN);
	}
	return (plane_transition_6(state, c));
}

t_p_state	plane_transition_6(t_p_state state, char c)
{
	if (state == P_NORMAL_X_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_X_BEFORE_DECIMAL);
	}
	else if (state == P_NORMAL_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_3);
		if (c == '.')
			return (P_NORMAL_X_DECIMAL);
	}
	else if (state == P_NORMAL_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_X_AFTER_DECIMAL);
	}
	else if (state == P_NORMAL_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_3);
		if (ft_isdigit(c))
			return (P_NORMAL_X_AFTER_DECIMAL);
	}
	return (plane_transition_7(state, c));
}

t_p_state	plane_transition_7(t_p_state state, char c)
{
	if (state == P_COMMA_3)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (P_NORMAL_Y_SIGN);
	}
	else if (state == P_NORMAL_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_BEFORE_DECIMAL);
	}
	else if (state == P_NORMAL_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_4);
		if (c == '.')
			return (P_NORMAL_Y_DECIMAL);
	}
	else if (state == P_NORMAL_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_AFTER_DECIMAL);
	}
	return (plane_transition_8(state, c));
}

t_p_state	plane_transition_8(t_p_state state, char c)
{
	if (state == P_NORMAL_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_4);
		if (ft_isdigit(c))
			return (P_NORMAL_Y_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_4)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (P_NORMAL_Z_SIGN);
	}
	else if (state == P_NORMAL_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_BEFORE_DECIMAL);
	}
	return (plane_transition_9(state, c));
}

t_p_state	plane_transition_9(t_p_state state, char c)
{
	if (state == P_NORMAL_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (c == '.')
			return (P_NORMAL_Z_DECIMAL);
	}
	else if (state == P_NORMAL_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_AFTER_DECIMAL);
	}
	else if (state == P_NORMAL_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (ft_isdigit(c))
			return (P_NORMAL_Z_AFTER_DECIMAL);
	}
	return (plane_transition_10(state, c));
}
