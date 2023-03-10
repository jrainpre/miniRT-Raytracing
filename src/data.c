#include "miniRT.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc_or_print_error(sizeof (t_data));
	if (data == NULL)
		return (NULL);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->scene = NULL;
	data->img = NULL;
	data->win = (t_resolution){640, 360};
	return (data);
}

void	*free_data_null(t_data *data)
{
	data->mlx_ptr = free_null(data->mlx_ptr);
	data->img = free_null(data->img);
	data->scene = free_scene_null(data->scene);
	data = free_null(data);
	return (data);
}
