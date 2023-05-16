/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_light1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:03 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 14:59:58 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_l_state	light_transition(t_l_state state, char c)
{
	if (state == L_START)
	{
		if (c == ' ')
			return (L_START);
		if (c == 'L')
			return (L_IDENTIFIER_1);
	}
	else if (state == L_IDENTIFIER_1)
	{
		if (c == ' ')
			return (L_SPACE_1);
	}
	else if (state == L_SPACE_1)
	{
		if (c == ' ')
			return (L_SPACE_1);
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_X_SIGN);
	}
	return (light_transition_1(state, c));
}

t_l_state	light_transition_1(t_l_state state, char c)
{
	if (state == L_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_1);
		if (c == '.')
			return (L_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_X_AFTER_DECIMAL);
	}
	return (light_transition_2(state, c));
}

t_l_state	light_transition_2(t_l_state state, char c)
{
	if (state == L_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_1);
		if (ft_isdigit(c))
			return (L_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == L_COMMA_1)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_Y_SIGN);
	}
	else if (state == L_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
	}
	return (light_transition_3(state, c));
}

t_l_state	light_transition_3(t_l_state state, char c)
{
	if (state == L_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_2);
		if (c == '.')
			return (L_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == L_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_2);
		if (ft_isdigit(c))
			return (L_ORIG_Y_AFTER_DECIMAL);
	}
	return (light_transition_4(state, c));
}

t_l_state	light_transition_4(t_l_state state, char c)
{
	if (state == L_COMMA_2)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_Z_SIGN);
	}
	else if (state == L_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (c == '.')
			return (L_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
	}
	return (light_transition_5(state, c));
}
