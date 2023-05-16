/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_sphere1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:02:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:05:28 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_s_state	sphere_transition(t_s_state state, char c)
{
	if (state == S_START)
	{
		if (c == ' ')
			return (S_START);
		if (c == 's')
			return (S_IDENTIFIER_1);
	}
	else if (state == S_IDENTIFIER_1)
	{
		if (c == 'p')
			return (S_IDENTIFIER_2);
	}
	else if (state == S_IDENTIFIER_2)
	{
		if (c == ' ')
			return (S_SPACE_1);
	}
	return (sphere_transition_1(state, c));
}

t_s_state	sphere_transition_1(t_s_state state, char c)
{
	if (state == S_SPACE_1)
	{
		if (c == ' ')
			return (S_SPACE_1);
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_X_SIGN);
	}
	else if (state == S_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_1);
		if (c == '.')
			return (S_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
	}
	return (sphere_transition_2(state, c));
}

t_s_state	sphere_transition_2(t_s_state state, char c)
{
	if (state == S_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_1);
		if (ft_isdigit(c))
			return (S_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == S_COMMA_1)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_Y_SIGN);
	}
	else if (state == S_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
	}
	return (sphere_transition_3(state, c));
}

t_s_state	sphere_transition_3(t_s_state state, char c)
{
	if (state == S_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_2);
		if (c == '.')
			return (S_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_2);
		if (ft_isdigit(c))
			return (S_ORIG_Y_AFTER_DECIMAL);
	}
	return (sphere_transition_4(state, c));
}

t_s_state	sphere_transition_4(t_s_state state, char c)
{
	if (state == S_COMMA_2)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_Z_SIGN);
	}
	else if (state == S_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (c == '.')
			return (S_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
	}
	return (sphere_transition_5(state, c));
}
