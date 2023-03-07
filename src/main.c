#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	if (start_mlx(&data) == -1)
		return (-1);
	return (0);
}
