/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:45:09 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:46:22 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define WIN_W 1920.0
# define WIN_H 1080.0

# include "sphere.h"
# include "light.h"
# include "ray.h"

typedef struct s_resolution
{
	int	width;
	int	height;
}			t_resolution;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_scene	*scene;
	t_lst_ref		*scene_lines;
	t_img			*img;
	t_resolution	win;
	t_color			*pixelcolors;
	int				pixelcolors_int;
	t_lst			*slected_obj;
}			t_data;

#endif