#include "miniRT.h"

t_camera	*init_camera(t_resolution win, char *line)
{
	t_camera	*cam;
	char		**parameters;
	char		**orig;
	char		**orientation;

	parameters = ft_split(line, ' ');
	if (parameters == NULL)
		return (NULL);
	orig = ft_split(parameters[1], ',');
	if (orig == NULL)
	{
		parameters = free_arr_null(parameters);
		return (NULL);
	}
	orientation = ft_split(parameters[2], ',');
	if (orientation == NULL)
	{
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		return (NULL);
	}
	cam = malloc_or_print_error(sizeof (t_camera));
	if (cam == NULL)
		return (NULL);
	cam->orig = get_vec_from_str_arr(orig);
	cam->orientation = get_vec_from_str_arr(orientation);
	if (!is_normalized(cam->orientation))
	{
		cam = free_null(cam);
		parameters = free_arr_null(parameters);
		orig = free_arr_null(orig);
		orientation = free_arr_null(orientation);
		return (NULL);
	}
	cam->fov = ft_atof(parameters[3]);
	cam->sensor_height = 0.024;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) * cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) / tanf(deg_to_rad(cam->fov / 2.0));
	if (cam->orientation.y == 1 || cam->orientation.y == -1)
		cam->horizontal = (t_vec3){1, 0, 0};
	else
		cam->horizontal = cross_prod(cam->orientation, (t_vec3){0, 1, 0});
	cam->horizontal = unit_vec3(cam->horizontal);
	cam->left = vec_mult(cam->horizontal, -1);
	print_vec3("cam->horizontal", cam->horizontal);
	cam->vertical = cross_prod(cam->orientation, cam->horizontal);
	cam->vertical = unit_vec3(cam->vertical);
	print_vec3("cam->vertical", cam->vertical);
	cam->up = vec_mult(cam->vertical, -1);
	cam->horizontal = vec_mult(cam->horizontal, cam->sensor_width);
	print_vec3("cam->horizontal", cam->horizontal);
	cam->vertical = vec_mult(cam->vertical, cam->sensor_height);
	print_vec3("cam->vertical", cam->vertical);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	orientation = free_arr_null(orientation);
	print_object(cam, CAMERA);
	return (cam);
}

t_vec3	calc_upper_left_corner(t_camera *cam)
{
	t_vec3	upper_left;
	t_vec3	mid;
	t_vec3	flipped_half_h;
	t_vec3	flipped_half_v;

	mid = vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length));
	flipped_half_h = vec_div(cam->horizontal, -2);
	flipped_half_v = vec_div(cam->vertical, -2);
	upper_left = vec_add(flipped_half_h, flipped_half_v);
	return (vec_add(mid, upper_left));
}

void	translate_camera(t_camera *cam, t_vec3 vec)
{
	cam->orig = vec_add(cam->orig, vec);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}

void	rotate_y_camera(t_camera *cam, float_t angle)
{
	cam->orientation = rotate_y(cam->orientation, angle);
	cam->left = rotate_y(cam->left, angle);
	cam->up = rotate_y(cam->up, angle);
	cam->horizontal = rotate_y(cam->horizontal, angle);
	cam->vertical = rotate_y(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}

void	rotate_x_camera(t_camera *cam, float_t angle)
{
	cam->orientation = rotate_x(cam->orientation, angle);
	cam->left = rotate_x(cam->left, angle);
	cam->up = rotate_x(cam->up, angle);
	// Check if I really have to rotate left and up
	cam->horizontal = rotate_x(cam->horizontal, angle);
	cam->vertical = rotate_x(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}

void	rotate_camera_around_left_axis(t_camera *cam, float_t angle)
{
	t_mat3x3	old_state;
	t_mat3x3	new_state;

	old_state = (t_mat3x3){
		cam->left.x, cam->up.x, cam->orientation.x,
		cam->left.y, cam->up.y, cam->orientation.y,
		cam->left.z, cam->up.z, cam->orientation.z
	};
	new_state = mat3x3_dot_prod(old_state, get_rot_x(angle));
	cam->orientation = mat_mult(new_state, (t_vec3){0, 0, 1});
	cam->left = mat_mult(new_state, (t_vec3){1, 0, 0});
	cam->up = mat_mult(new_state, (t_vec3){0, 1, 0});
	cam->vertical = mat_mult(new_state, (t_vec3){0, -cam->sensor_height, 0});
	cam->horizontal = mat_mult(new_state, (t_vec3){-cam->sensor_width, 0, 0});
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}

void	tilt_down(t_camera *cam, float_t angle)
{
	rotate_camera_around_left_axis(cam, angle);
}

void	tilt_up(t_camera *cam, float_t angle)
{
	rotate_camera_around_left_axis(cam, -angle);
}

void	dolly_in(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->orientation, meters));
}

void	dolly_out(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->orientation, -meters));
}

void	truck_left(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->left, meters));
}

void	truck_right(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult(cam->left, -meters));
}

void	pedestal_up(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult((t_vec3){0, 1, 0}, meters));
}

void	pedestal_down(t_camera *cam, float_t meters)
{
	translate_camera(cam, vec_mult((t_vec3){0, 1, 0}, -meters));
}

void	pan_left(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, angle);
}

void	pan_right(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, -angle);
}
