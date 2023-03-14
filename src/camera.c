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
	// check if orientation vector is normalized!
	cam->rot_y_angle = acosf(cam->orientation.z);
	cam->rot_x_angle = asinf(-cam->orientation.y);
	cam->fov = ft_atof(parameters[3]);
	cam->sensor_height = 0.024;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) * cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) / tanf(deg_to_rad(cam->fov / 2.0));
	cam->vertical = (t_vec3){0, -cam->sensor_height, 0};
	cam->vertical = rotate_x(rotate_y(cam->vertical, cam->rot_y_angle), cam->rot_x_angle);
	cam->horizontal = (t_vec3){-cam->sensor_width, 0, 0};
	cam->horizontal = rotate_x(rotate_y(cam->horizontal, cam->rot_y_angle), cam->rot_x_angle);
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
	cam->horizontal = rotate_y(cam->horizontal, angle);
	cam->vertical = rotate_y(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}

void	rotate_x_camera(t_camera *cam, float_t angle)
{
	cam->orientation = rotate_x(cam->orientation, angle);
	cam->horizontal = rotate_x(cam->horizontal, angle);
	cam->vertical = rotate_x(cam->vertical, angle);
	cam->upper_left_corner = calc_upper_left_corner(cam);
	print_object(cam, CAMERA);
}
