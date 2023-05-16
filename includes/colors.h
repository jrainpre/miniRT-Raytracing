/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:44:43 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:46:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "vector.h"

# define RED	0x00FF0000
# define DRED	0x00660000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define DBLUE	0x00000066
# define PURPLE	0x00B491C8
# define WHITE	0x00FFFFFF
# define DGREEN	0x00006600
# define BLACK	0x00000000
# define GREY	0x00888888
# define DGREY	0x00333333
# define NOCOLOR	0x00000000

typedef struct s_color
{
	float_t	r;
	float_t	g;
	float_t	b;
	float_t	a;
}				t_color;

#endif
