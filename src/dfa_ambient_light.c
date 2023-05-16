/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:38:53 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:38:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_a_state	ambient_light_transition(t_a_state state, char c)
{
	if (state == A_START)
	{
		if (c == ' ')
			return (A_START);
		if (c == 'A')
			return (A_IDENTIFIER);
	}
	else if (state == A_IDENTIFIER)
	{
		if (c == ' ')
			return (A_SPACE_1);
	}
	else if (state == A_SPACE_1)
	{
		if (c == ' ')
			return (A_SPACE_1);
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_BEFORE_DECIMAL);
	}
	return (ambient_light_transition_1(state, c));
}

t_a_state	ambient_light_transition_1(t_a_state state, char c)
{
	if (state == A_LIGHT_RATIO_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (c == '.')
			return (A_LIGHT_RATIO_DECIMAL);
	}
	else if (state == A_LIGHT_RATIO_DECIMAL)
	{
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_AFTER_DECIMAL);
	}
	else if (state == A_LIGHT_RATIO_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_AFTER_DECIMAL);
	}
	return (ambient_light_transition_2(state, c));
}

t_a_state	ambient_light_transition_2(t_a_state state, char c)
{
	if (state == A_SPACE_2)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (ft_isdigit(c))
			return (A_RED);
	}
	else if (state == A_RED)
	{
		if (c == ',')
			return (A_COMMA_1);
		if (ft_isdigit(c))
			return (A_RED);
	}
	else if (state == A_COMMA_1)
	{
		if (ft_isdigit(c))
			return (A_GREEN);
	}
	return (ambient_light_transition_3(state, c));
}

t_a_state	ambient_light_transition_3(t_a_state state, char c)
{
	if (state == A_GREEN)
	{
		if (c == ',')
			return (A_COMMA_2);
		if (ft_isdigit(c))
			return (A_GREEN);
	}
	else if (state == A_COMMA_2)
	{
		if (ft_isdigit(c))
			return (A_BLUE);
	}
	else if (state == A_BLUE)
	{
		if (ft_isdigit(c))
			return (A_BLUE);
		if (c == '\n')
			return (A_ACCEPT);
		if (c == ' ')
			return (A_SPACE_3);
	}
	return (ambient_light_transition_4(state, c));
}

t_a_state	ambient_light_transition_4(t_a_state state, char c)
{
	if (state == A_SPACE_3)
	{
		if (c == ' ')
			return (A_SPACE_3);
		if (c == '\n')
			return (A_ACCEPT);
	}
	else if (state == A_ACCEPT)
		return (A_ACCEPT);
	return (A_REJECT);
}
