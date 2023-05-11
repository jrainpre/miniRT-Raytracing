#include "miniRT.h"

int	loop_hook(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_scene(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	render_status(data, WHITE);
	return (0);
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

void	increase_diameter_sphere(t_lst *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	sphere->radius += 0.1;
}

void	decrease_diameter_sphere(t_lst *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	if (sphere->radius > 0.1)
		sphere->radius -= 0.1;
}

void	increase_diameter_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	cylinder->radius += 0.1;
}

void	decrease_diameter_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	if (cylinder->radius > 0.1)
		cylinder->radius -= 0.1;
}

void	increase_hight_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	cylinder->height += 0.1;
}

void	decrease_hight_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	if (cylinder->height > 0.1)
		cylinder->height -= 0.1;
}

void	object_resize_up(t_lst *object)
{
	if (object->type == SPHERE)
		increase_diameter_sphere(object->content);
	if (object->type == CYLINDER)
		increase_diameter_cylinder(object->content);
}

void	object_resize_down(t_lst *object)
{
	if (object->type == SPHERE)
		decrease_diameter_sphere(object->content);
	if (object->type == CYLINDER)
		decrease_diameter_cylinder(object->content);
}

void	object_resize_left(t_lst *object)
{
	if (object->type == CYLINDER)
		increase_hight_cylinder(object->content);
}

void	object_resize_right(t_lst *object)
{
	if (object->type == CYLINDER)
		decrease_hight_cylinder(object->content);
}

void	translate_obj_inc_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x += 0.1;
}

void	translate_obj_dec_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x -= 0.1;
}

void	translate_obj_inc_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y += 0.1;
}

void	translate_obj_dec_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y -= 0.1;
}

void	translate_obj_inc_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z += 0.1;
}

void	translate_obj_dec_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z -= 0.1;
}

void	rotate_obj_inc_x(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_x(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_x(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_dec_x(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_x(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_x(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_inc_y(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_y(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_y(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_dec_y(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_y(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_y(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_inc_z(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_z(((t_cylinder *)object->content)->axis, M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_z(((t_plane *)object->content)->normal_vec, M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

void	rotate_obj_dec_z(t_lst *object)
{
	t_vec3	axis;

	if (object->type == CYLINDER)
	{
		axis = rotate_z(((t_cylinder *)object->content)->axis, -M_PI_4 / 4);
		((t_cylinder *)object->content)->axis = unit_vec3(axis);
	}
	if (object->type == PLANE)
	{
		axis = rotate_z(((t_plane *)object->content)->normal_vec, -M_PI_4 / 4);
		((t_plane *)object->content)->normal_vec = unit_vec3(axis);
	}
}

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

void	object_actions(int keysym, t_data *data)
{
	object_translate(keysym, data);
	object_resize(keysym, data);
	object_rotate(keysym, data);
}

int	key_hook1(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_app(data);
	if (keysym == XK_n)
		select_next_object(data);
	if (keysym == XK_m && data->slected_obj != NULL)
	{
		data->slected_obj->is_slected = 0;
		data->slected_obj = NULL;
	}
	if (data->slected_obj != NULL)
		object_actions(keysym, data);
	else
		scene_actions(keysym, data);
	data->pixelcolors_int = 1;
	ft_memset(data->pixelcolors, 0, data->win.width * data->win.height
		* sizeof(t_color));
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

void	init_pixelcolors(t_data *data)
{
	data->pixelcolors = calloc_or_print_error(data->win.width * \
	data->win.height, sizeof(t_color));
	data->pixelcolors_int = 1;
}

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_putstr_fd("Failed to set up the connection to the X server\n", 2);
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win.width,
			data->win.height, "miniRT");
	if (data->win_ptr == NULL)
		ft_putstr_fd("Failed to create a new window\n", 2);
	if (data->win_ptr == NULL)
		return (-1);
	data->img = malloc_or_print_error(sizeof(t_img));
	init_pixelcolors(data);
	if (data->img == NULL || data->pixelcolors == NULL)
		return (-1);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->win.width,
			data->win.height);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, close_app, data);
	mlx_hook(data->win_ptr, KeyPress, 1, key_hook1, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
