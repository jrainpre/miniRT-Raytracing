/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_plane1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 15:10:43 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_p_state	plane_transition(t_p_state state, char c)
{
	if (state == P_START)
	{
		if (c == ' ')
			return (P_START);
		if (c == 'p')
			return (P_IDENTIFIER_1);
	}
	else if (state == P_IDENTIFIER_1)
	{
		if (c == 'l')
			return (P_IDENTIFIER_2);
	}
	else if (state == P_IDENTIFIER_2)
	{
		if (c == ' ')
			return (P_SPACE_1);
	}
	return (plane_transition_1(state, c));
}

t_p_state	plane_transition_1(t_p_state state, char c)
{
	if (state == P_SPACE_1)
	{
		if (c == ' ')
			return (P_SPACE_1);
		if (c == '-' || c == '+')
			return (P_ORIG_X_SIGN);
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_1);
		if (c == '.')
			return (P_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	return (plane_transition_2(state, c));
}

t_p_state	plane_transition_2(t_p_state state, char c)
{
	if (state == P_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_1);
		if (ft_isdigit(c))
			return (P_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_1)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (P_ORIG_Y_SIGN);
	}
	else if (state == P_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
	}
	return (plane_transition_3(state, c));
}

t_p_state	plane_transition_3(t_p_state state, char c)
{
	if (state == P_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_2);
		if (c == '.')
			return (P_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_2);
		if (ft_isdigit(c))
			return (P_ORIG_Y_AFTER_DECIMAL);
	}
	return (plane_transition_4(state, c));
}

t_p_state	plane_transition_4(t_p_state state, char c)
{
	if (state == P_COMMA_2)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (P_ORIG_Z_SIGN);
	}
	else if (state == P_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (c == '.')
			return (P_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
	}
	return (plane_transition_5(state, c));
}
