/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:13:36 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cy_state	cylinder_transition_5(t_cy_state state, char c)
{
	if (state == CY_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_2)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
		if (c == ' ')
			return (CY_AXIS_X_SIGN);
	}
	return (cylinder_transition_6(state, c));
}

t_cy_state	cylinder_transition_6(t_cy_state state, char c)
{
	if (state == CY_AXIS_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (c == '.')
			return (CY_AXIS_X_DECIMAL);
	}
	else if (state == CY_AXIS_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	return (cylinder_transition_7(state, c));
}

t_cy_state	cylinder_transition_7(t_cy_state state, char c)
{
	if (state == CY_COMMA_3)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_AXIS_Y_SIGN);
	}
	else if (state == CY_AXIS_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (c == '.')
			return (CY_AXIS_Y_DECIMAL);
	}
	else if (state == CY_AXIS_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	return (cylinder_transition_8(state, c));
}

t_cy_state	cylinder_transition_8(t_cy_state state, char c)
{
	if (state == CY_AXIS_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_4)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_AXIS_Z_SIGN);
	}
	else if (state == CY_AXIS_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
	}
	return (cylinder_transition_9(state, c));
}

t_cy_state	cylinder_transition_9(t_cy_state state, char c)
{
	if (state == CY_AXIS_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (c == '.')
			return (CY_AXIS_Z_DECIMAL);
	}
	else if (state == CY_AXIS_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	return (cylinder_transition_10(state, c));
}
