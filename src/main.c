#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	test_ft_atof();
	if (!arguments_valid(argc, argv))
		return (1);
	data = init_data();
	if (data == NULL)
		return (1);
	data->scene_arr = read_file(argv[1]);
	if (data->scene_arr == NULL)
	{
		data = free_data_null(data);
		return (1);
	}
	if (!is_valid_scene(data->scene_arr))
	{
		data = free_data_null(data);
		return (1);
	}
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
