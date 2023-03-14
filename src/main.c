#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	if (!arguments_valid(argc, argv))
		return (1);
	data = init_data();
	if (data == NULL)
		return (1);
	data->scene = init_scene();
	if (data->scene == NULL)
	{
		data->scene = free_scene_null(data->scene);
		data = free_data_null(data);
		return (1);
	}
	if (fill_dummy_scene(data) == -1)
	{
		data->scene = free_scene_null(data->scene);
		data = free_data_null(data);
		return (1);
	}
	if (start_mlx(data) == -1)
	{
		data = free_data_null(data);
		return (-1);
	}
	return (0);
}
