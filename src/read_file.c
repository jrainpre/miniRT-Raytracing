/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:45 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:46 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	wrapper_open(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		perror("open");
		exit(1);
	}
}

void	wrapper_close(int *fd)
{
	if (close(*fd) == -1)
	{
		perror("close");
		exit(1);
	}
}

t_lst_ref	*read_file(char *file)
{
	int			fd;
	t_lst_ref	*scene_lines;
	char		*line;

	scene_lines = malloc_or_print_error(sizeof(t_lst_ref));
	if (scene_lines == NULL)
		return (NULL);
	scene_lines->head = NULL;
	scene_lines->last = NULL;
	fd = open(file, O_RDONLY);
	wrapper_open(file, &fd);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			ft_add_lst_last(ft_lstnew(line), scene_lines);
	}
	wrapper_close(&fd);
	return (scene_lines);
}
