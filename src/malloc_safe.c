/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:15:00 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 23:15:01 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*malloc_or_print_error(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}

void	*calloc_or_print_error(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
	{
		ft_putstr_fd("calloc error\n", STDERR_FILENO);
		return (NULL);
	}
	return (ptr);
}
