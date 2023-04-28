#include "miniRT.h"

void	render_status(t_data *data, int color)
{
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
	// 	color, "Zoom: Keypad +, -");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 50,
	// 	color, "Translate: Up, Down, Left, Right");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 70,
	// 	color, "Rotate: W, A, S, D");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 90,
	// 	color, "Change Height: J, K");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 110,
	// 	color, "Reset Isometric View: R");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 130,
	// 	color, "Top View: T");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 150,
	// 	color, "Animate: Space");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
		color, "Camera Orientation");
	char x[200];
	sprintf(x, "x: %10.4f", data->scene->cam->orientation.x);
	char y[200];
	sprintf(y, "y: %10.4f", data->scene->cam->orientation.y);
	char z[200];
	sprintf(z, "z: %10.4f", data->scene->cam->orientation.z);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 50,
		color, x);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 70,
		color, y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 90,
		color, z);
}
