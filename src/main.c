#include "miniRT.h"


int	main(int argc, char **argv)
{
	srand(time(NULL));
	t_data	*data;

	(void)argc;
	(void)argv;
	if (!arguments_valid(argc, argv))
		return (1);
	data = init_data();
	if (data == NULL)
		return (1);
	data->scene_lines = read_file(argv[1]);
	if (data->scene_lines == NULL)
	{
		data = free_data_null(data);
		return (1);
	}
	if (!is_valid_scene(data->scene_lines))
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
	if (fill_scene(data->scene, data->scene_lines, data->win) == -1)
	{
		data->scene = free_scene_null(data->scene);
		data = free_data_null(data);
		return (1);
	}
	t_sphere *sphere = data->scene->objects->head->content;
	sphere->reflect_factor = 0.99;
	// sphere = data->scene->objects->head->next->content;
	// sphere->reflect_factor = 0.5;
	if (start_mlx(data) == -1)
	{
		data = free_data_null(data);
		return (-1);
	}
	return (0);
}
