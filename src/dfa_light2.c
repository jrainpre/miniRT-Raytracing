/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_light2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:03 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 15:03:00 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_l_state	light_transition_5(t_l_state state, char c)
{
	if (state == L_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == L_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (ft_isdigit(c))
			return (L_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == L_SPACE_2)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_BEFORE_DECIMAL);
	}
	return (light_transition_6(state, c));
}

t_l_state	light_transition_6(t_l_state state, char c)
{
	if (state == L_BRIGHTNESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (c == '.')
			return (L_BRIGHTNESS_DECIMAL);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_BEFORE_DECIMAL);
	}
	else if (state == L_BRIGHTNESS_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_AFTER_DECIMAL);
	}
	else if (state == L_BRIGHTNESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_AFTER_DECIMAL);
	}
	return (light_transition_7(state, c));
}

t_l_state	light_transition_7(t_l_state state, char c)
{
	if (state == L_SPACE_3)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (ft_isdigit(c))
			return (L_RED);
	}
	else if (state == L_RED)
	{
		if (c == ',')
			return (L_COMMA_3);
		if (ft_isdigit(c))
			return (L_RED);
	}
	else if (state == L_COMMA_3)
	{
		if (ft_isdigit(c))
			return (L_GREEN);
	}
	return (light_transition_8(state, c));
}

t_l_state	light_transition_8(t_l_state state, char c)
{
	if (state == L_GREEN)
	{
		if (c == ',')
			return (L_COMMA_4);
		if (ft_isdigit(c))
			return (L_GREEN);
	}
	else if (state == L_COMMA_4)
	{
		if (ft_isdigit(c))
			return (L_BLUE);
	}
	else if (state == L_BLUE)
	{
		if (ft_isdigit(c))
			return (L_BLUE);
		if (c == '\n')
			return (L_ACCEPT);
		if (c == ' ')
			return (L_SPACE_4);
	}
	return (light_transition_9(state, c));
}

t_l_state	light_transition_9(t_l_state state, char c)
{
	if (state == L_SPACE_4)
	{
		if (c == ' ')
			return (L_SPACE_4);
		if (c == '\n')
			return (L_ACCEPT);
	}
	else if (state == L_ACCEPT)
		return (L_ACCEPT);
	return (L_REJECT);
}
