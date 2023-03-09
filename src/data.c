#include "miniRT.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (data == NULL)
	{
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
		return (NULL);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->scene = NULL;
	return (data);
}

void	*free_data_null(t_data *data)
{
	data->mlx_ptr = free_null(data->mlx_ptr);
	data->scene = free_scene_null(data->scene);
	data = free_null(data);
	return (data);
}
