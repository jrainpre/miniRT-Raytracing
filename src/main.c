#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_scene scene;

	(void)argc;
	(void)argv;
	init_scene(&scene);
	fill_dummy_scene(&scene);
	data.scene = &scene;
	if (start_mlx(&data) == -1)
		return (-1);

	return (0);
}
