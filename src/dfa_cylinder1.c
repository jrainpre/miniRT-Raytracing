/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_cylinder1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:11:40 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cy_state	cylinder_transition(t_cy_state state, char c)
{
	if (state == CY_START)
	{
		if (c == ' ')
			return (CY_START);
		if (c == 'c')
			return (CY_IDENTIFIER_1);
	}
	else if (state == CY_IDENTIFIER_1)
	{
		if (c == 'y')
			return (CY_IDENTIFIER_2);
	}
	else if (state == CY_IDENTIFIER_2)
	{
		if (c == ' ')
			return (CY_SPACE_1);
	}
	return (cylinder_transition_1(state, c));
}

t_cy_state	cylinder_transition_1(t_cy_state state, char c)
{
	if (state == CY_SPACE_1)
	{
		if (c == ' ')
			return (CY_SPACE_1);
		if (c == '-' || c == '+')
			return (CY_ORIG_X_SIGN);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (c == '.')
			return (CY_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	return (cylinder_transition_2(state, c));
}

t_cy_state	cylinder_transition_2(t_cy_state state, char c)
{
	if (state == CY_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_1)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_ORIG_Y_SIGN);
	}
	else if (state == CY_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	return (cylinder_transition_3(state, c));
}

t_cy_state	cylinder_transition_3(t_cy_state state, char c)
{
	if (state == CY_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (c == '.')
			return (CY_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	return (cylinder_transition_4(state, c));
}

t_cy_state	cylinder_transition_4(t_cy_state state, char c)
{
	if (state == CY_COMMA_2)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_ORIG_Z_SIGN);
	}
	else if (state == CY_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (c == '.')
			return (CY_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	return (cylinder_transition_5(state, c));
}
