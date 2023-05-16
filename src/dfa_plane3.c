/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_plane3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 15:14:45 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_p_state	plane_transition_10(t_p_state state, char c)
{
	if (state == P_SPACE_3)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (ft_isdigit(c))
			return (P_RED);
	}
	else if (state == P_RED)
	{
		if (c == ',')
			return (P_COMMA_5);
		if (ft_isdigit(c))
			return (P_RED);
	}
	else if (state == P_COMMA_5)
	{
		if (ft_isdigit(c))
			return (P_GREEN);
	}
	return (plane_transition_11(state, c));
}

t_p_state	plane_transition_11(t_p_state state, char c)
{
	if (state == P_GREEN)
	{
		if (c == ',')
			return (P_COMMA_6);
		if (ft_isdigit(c))
			return (P_GREEN);
	}
	else if (state == P_COMMA_6)
	{
		if (ft_isdigit(c))
			return (P_BLUE);
	}
	else if (state == P_BLUE)
	{
		if (ft_isdigit(c))
			return (P_BLUE);
		if (c == '\n')
			return (P_ACCEPT);
		if (c == ' ')
			return (P_SPACE_4);
	}
	return (plane_transition_12(state, c));
}

t_p_state	plane_transition_12(t_p_state state, char c)
{
	if (state == P_SPACE_4)
	{
		if (c == ' ')
			return (P_SPACE_4);
		if (c == '\n')
			return (P_ACCEPT);
		if (ft_isdigit(c))
			return (P_REFLECTIVENESS_BEFORE_DECIMAL);
	}
	else if (state == P_REFLECTIVENESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_5);
		if (c == '.')
			return (P_REFLECTIVENESS_DECIMAL);
		if (ft_isdigit(c))
			return (P_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (P_ACCEPT);
	}
	return (plane_transition_13(state, c));
}

t_p_state	plane_transition_13(t_p_state state, char c)
{
	if (state == P_SPACE_5)
	{
		if (c == ' ')
			return (P_SPACE_5);
		if (ft_isdigit(c))
			return (P_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '.')
			return (P_REFLECTIVENESS_DECIMAL);
		if (c == '\n')
			return (P_ACCEPT);
	}
	else if (state == P_REFLECTIVENESS_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_REFLECTIVENESS_AFTER_DECIMAL);
	}
	return (plane_transition_14(state, c));
}

t_p_state	plane_transition_14(t_p_state state, char c)
{
	if (state == P_REFLECTIVENESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_5);
		if (ft_isdigit(c))
			return (P_REFLECTIVENESS_AFTER_DECIMAL);
		if (c == '\n')
			return (P_ACCEPT);
	}
	else if (state == P_ACCEPT)
		return (P_ACCEPT);
	return (P_REJECT);
}
