#include "miniRT.h"

int	loop_hook(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, BLACK);
	render_scene(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	return (0);
}

int	key_hook1(int keysym, t_data *data)
{
	printf("%x\n", keysym);
	if (keysym == XK_Escape)
		close_app(data);
	if (keysym == XK_Left)
		truck_left(data->scene->cam, 0.1);
	if (keysym == XK_Right)
		truck_right(data->scene->cam, 0.1);
	if (keysym == XK_Up)
		pedestal_up(data->scene->cam, 0.1);
	if (keysym == XK_Down)
		pedestal_down(data->scene->cam, 0.1);
	if (keysym == XK_i)
		dolly_in(data->scene->cam, 0.1);
	if (keysym == XK_o)
		dolly_out(data->scene->cam, 0.1);
	if (keysym == XK_q)
		pan_left(data->scene->cam, M_PI_4 / 4);
	if (keysym == XK_e)
		pan_right(data->scene->cam, M_PI_4 / 4);
	if (keysym == XK_r)
		tilt_up(data->scene->cam, M_PI_4 / 4);
	if (keysym == XK_f)
		tilt_down(data->scene->cam, M_PI_4 / 4);
	if (keysym == XK_a)
		translate_light(data->scene->light, (t_vec3){-10, 0, 0});
	if (keysym == XK_d)
		translate_light(data->scene->light, (t_vec3){10, 0, 0});
	if (keysym == XK_w)
		translate_light(data->scene->light, (t_vec3){0, 10, 0});
	if (keysym == XK_s)
		translate_light(data->scene->light, (t_vec3){0, -10, 0});
	data->pixelcolors_int = 1;
	ft_memset(data->pixelcolors, 0, data->win.width * data->win.height * sizeof (t_color));
	print_object(data->scene->cam, CAMERA);
	return (0);
}

int	close_app(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	data = free_data_null(data);
	exit(0);
	return (0);
}

int	start_mlx(t_data *data)
{
	data->pixelcolors = ft_calloc(data->win.width * data->win.height, sizeof (t_color));
	data->pixelcolors_int = 1;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_putstr_fd("Failed to set up the connection to the X server\n", 2);
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width, data->win.height, "miniRT");
	if (data->win_ptr == NULL)
		ft_putstr_fd("Failed to create a new window\n", 2);
	if (data->win_ptr == NULL)
		return (-1);
	data->img = malloc_or_print_error(sizeof (t_img));
	if (data->img == NULL)
		return (-1);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->win.width, data->win.height);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, close_app, data);
	mlx_hook(data->win_ptr, KeyPress, 1, key_hook1, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
