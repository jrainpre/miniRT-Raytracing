/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:13:51 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:13:52 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	ft_atof(const char *str)
{
	double	num;
	double	decimal;
	int		i;
	int		sign;
	int		decimal_digits;

	i = 0;
	while (str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	num = ft_atoi(str);
	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (num);
	i++;
	decimal = ft_atoi(str + i);
	decimal_digits = 0;
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		decimal_digits++;
		i++;
	}
	num = num + sign * (decimal / pow(10, decimal_digits));
	return (num);
}
