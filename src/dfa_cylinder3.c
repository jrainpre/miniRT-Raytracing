/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_cylinder3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:15:25 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cy_state	cylinder_transition_10(t_cy_state state, char c)
{
	if (state == CY_SPACE_3)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (c == '.')
			return (CY_DIAMETER_DECIMAL);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	return (cylinder_transition_11(state, c));
}

t_cy_state	cylinder_transition_11(t_cy_state state, char c)
{
	if (state == CY_DIAMETER_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_4)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	else if (state == CY_HEIGHT_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (c == '.')
			return (CY_HEIGHT_DECIMAL);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	return (cylinder_transition_12(state, c));
}

t_cy_state	cylinder_transition_12(t_cy_state state, char c)
{
	if (state == CY_HEIGHT_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_HEIGHT_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_5)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	return (cylinder_transition_13(state, c));
}

t_cy_state	cylinder_transition_13(t_cy_state state, char c)
{
	if (state == CY_RED)
	{
		if (c == ',')
			return (CY_COMMA_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	else if (state == CY_COMMA_5)
	{
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_GREEN)
	{
		if (c == ',')
			return (CY_COMMA_6);
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_COMMA_6)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
	}
	return (cylinder_transition_14(state, c));
}

t_cy_state	cylinder_transition_14(t_cy_state state, char c)
{
	if (state == CY_BLUE)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
		if (c == '\n')
			return (CY_ACCEPT);
		if (c == ' ')
			return (CY_SPACE_6);
	}
	else if (state == CY_SPACE_6)
	{
		if (c == ' ')
			return (CY_SPACE_6);
		if (ft_isdigit(c))
			return (CY_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	return (cylinder_transition_15(state, c));
}
