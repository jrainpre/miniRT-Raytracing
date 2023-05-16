/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:04 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:05 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float_t	clamp(float_t value, float_t min, float_t max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float_t	deg_to_rad(float_t deg)
{
	return (deg * (M_PI / 180.0));
}
