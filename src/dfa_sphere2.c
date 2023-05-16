/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_sphere2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:02:18 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:08:15 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_s_state	sphere_transition_5(t_s_state state, char c)
{
	if (state == S_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (ft_isdigit(c))
			return (S_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == S_SPACE_2)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (ft_isdigit(c))
			return (S_DIAMETER_BEFORE_DECIMAL);
	}
	return (sphere_transition_6(state, c));
}

t_s_state	sphere_transition_6(t_s_state state, char c)
{
	if (state == S_DIAMETER_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (c == '.')
			return (S_DIAMETER_DECIMAL);
		if (ft_isdigit(c))
			return (S_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == S_DIAMETER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == S_DIAMETER_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (ft_isdigit(c))
			return (S_DIAMETER_AFTER_DECIMAL);
	}
	return (sphere_transition_7(state, c));
}

t_s_state	sphere_transition_7(t_s_state state, char c)
{
	if (state == S_SPACE_3)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (ft_isdigit(c))
			return (S_RED);
	}
	else if (state == S_RED)
	{
		if (c == ',')
			return (S_COMMA_3);
		if (ft_isdigit(c))
			return (S_RED);
	}
	else if (state == S_COMMA_3)
	{
		if (ft_isdigit(c))
			return (S_GREEN);
	}
	return (sphere_transition_8(state, c));
}

t_s_state	sphere_transition_8(t_s_state state, char c)
{
	if (state == S_GREEN)
	{
		if (c == ',')
			return (S_COMMA_4);
		if (ft_isdigit(c))
			return (S_GREEN);
	}
	else if (state == S_COMMA_4)
	{
		if (ft_isdigit(c))
			return (S_BLUE);
	}
	else if (state == S_BLUE)
	{
		if (ft_isdigit(c))
			return (S_BLUE);
		if (c == '\n')
			return (S_ACCEPT);
		if (c == ' ')
			return (S_SPACE_4);
	}
	return (sphere_transition_9(state, c));
}

t_s_state	sphere_transition_9(t_s_state state, char c)
{
	if (state == S_SPACE_4)
	{
		if (c == ' ')
			return (S_SPACE_4);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_REFLECTIVENESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (c == '.')
			return (S_REFLECTIVENESS_DECIMAL);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	return (sphere_transition_10(state, c));
}
