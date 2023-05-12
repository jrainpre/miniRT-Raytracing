#include "miniRT.h"

void	light_actions(int keysym, t_data *data)
{
	if (keysym == XK_a)
		translate_light(data->scene->light, (t_vec3){-10, 0, 0});
	if (keysym == XK_d)
		translate_light(data->scene->light, (t_vec3){10, 0, 0});
	if (keysym == XK_w)
		translate_light(data->scene->light, (t_vec3){0, 10, 0});
	if (keysym == XK_s)
		translate_light(data->scene->light, (t_vec3){0, -10, 0});
	if (keysym == XK_y)
		translate_light(data->scene->light, (t_vec3){0, 0, 10});
	if (keysym == XK_x)
		translate_light(data->scene->light, (t_vec3){0, 0, -10});
}

void	camera_actions(int keysym, t_data *data)
{
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
}

void	scene_actions(int keysym, t_data *data)
{
	camera_actions(keysym, data);
	light_actions(keysym, data);
}
