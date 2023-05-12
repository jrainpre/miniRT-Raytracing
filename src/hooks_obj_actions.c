#include "miniRT.h"

void	object_rotate(int keysym, t_data *data)
{
	if (keysym == XK_t)
		rotate_obj_inc_x(data->slected_obj);
	if (keysym == XK_g)
		rotate_obj_dec_x(data->slected_obj);
	if (keysym == XK_h)
		rotate_obj_inc_y(data->slected_obj);
	if (keysym == XK_f)
		rotate_obj_dec_y(data->slected_obj);
	if (keysym == XK_r)
		rotate_obj_inc_z(data->slected_obj);
	if (keysym == XK_z)
		rotate_obj_dec_z(data->slected_obj);
}

void	object_resize(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		object_resize_up(data->slected_obj);
	if (keysym == XK_Down)
		object_resize_down(data->slected_obj);
	if (keysym == XK_Left)
		object_resize_left(data->slected_obj);
	if (keysym == XK_Right)
		object_resize_right(data->slected_obj);
}

void	object_translate(int keysym, t_data *data)
{
	if (keysym == XK_d)
		translate_obj_inc_x(data->slected_obj);
	if (keysym == XK_a)
		translate_obj_dec_x(data->slected_obj);
	if (keysym == XK_w)
		translate_obj_inc_y(data->slected_obj);
	if (keysym == XK_s)
		translate_obj_dec_y(data->slected_obj);
	if (keysym == XK_o)
		translate_obj_inc_z(data->slected_obj);
	if (keysym == XK_i)
		translate_obj_dec_z(data->slected_obj);
}

void	object_actions(int keysym, t_data *data)
{
	object_translate(keysym, data);
	object_resize(keysym, data);
	object_rotate(keysym, data);
}

void	select_next_object(t_data *data)
{
	if (data->slected_obj != NULL)
		data->slected_obj->is_slected = 0;
	if (data->slected_obj == NULL)
		data->slected_obj = data->scene->objects->head;
	else
		data->slected_obj = data->slected_obj->next;
	if (data->slected_obj != NULL)
		data->slected_obj->is_slected = 1;
}
