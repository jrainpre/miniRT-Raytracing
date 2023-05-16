/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:39:54 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 12:42:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	win_size_valid(int argc, char **argv)
{
	int		win_x;
	int		win_y;

	if (argc == 4)
	{
		win_x = ft_atoi(argv[2]);
		win_y = ft_atoi(argv[3]);
		if (win_x < 300 || win_x > 1920)
		{
			ft_putstr_fd("Error\nwin_x must be in 300..1920\n", STDERR_FILENO);
			return (0);
		}
		if (win_y < 300 || win_y > 1080)
		{
			ft_putstr_fd("Error\nwin_y must be in 300..1080\n", STDERR_FILENO);
			return (0);
		}
	}
	return (1);
}

int	arguments_valid(int argc, char **argv)
{
	char	*file_ext_pos;

	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("Error\nUsage: ./miniRT <scenefile.rt> [win_x win_y]\n",
			STDERR_FILENO);
		return (0);
	}
	file_ext_pos = ft_strnstr(argv[1], ".rt", ft_strlen(argv[1]));
	if (file_ext_pos == NULL || ft_strlen(file_ext_pos) != 3)
	{
		ft_putstr_fd("Error\nFile doesn't end with .rt\n", STDERR_FILENO);
		return (0);
	}
	if (!win_size_valid(argc, argv))
		return (0);
	return (1);
}
