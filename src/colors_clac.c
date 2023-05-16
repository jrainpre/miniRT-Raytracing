/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_clac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:12:55 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:12:56 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_mult(t_color color, float_t factor)
{
	t_color	prod;

	prod.r = color.r * factor;
	prod.g = color.g * factor;
	prod.b = color.b * factor;
	prod.a = color.a;
	return (prod);
}

t_color	color_add(t_color color1, t_color color2)
{
	t_color	sum;

	sum.r = color1.r + color2.r;
	sum.g = color1.g + color2.g;
	sum.b = color1.b + color2.b;
	sum.a = color1.a + color2.a;
	return (sum);
}

t_color	color_mult_color(t_color color1, t_color color2)
{
	t_color	prod;

	prod.r = color1.r * color2.r;
	prod.g = color1.g * color2.g;
	prod.b = color1.b * color2.b;
	prod.a = color1.a * color2.a;
	return (prod);
}

t_color	color_add_factor(t_color color, float_t factor)
{
	t_color	sum;

	sum.r = color.r + factor;
	sum.g = color.g + factor;
	sum.b = color.b + factor;
	sum.a = color.a + factor;
	return (sum);
}

t_color	color_div(t_color color, float_t div)
{
	t_color	new_color;

	new_color.r = color.r / div;
	new_color.g = color.g / div;
	new_color.b = color.b / div;
	new_color.a = color.a;
	return (new_color);
}
