#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = init_data();
	if (data == NULL)
		return (1);
	data->scene = init_scene();
	if (data->scene == NULL)
		return (1);
	fill_dummy_scene(data->scene);
	if (start_mlx(data) == -1)
		return (-1);
	return (0);
}
