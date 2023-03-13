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
	cam->fov = ft_atof(parameters[3]);
	cam->sensor_height = 0.024;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) * cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) / tanf(deg_to_rad(cam->fov / 2.0));
	cam->vertical = (t_vec3){0, -cam->sensor_height, 0};
	cam->horizontal = (t_vec3){cam->sensor_width, 0, 0};
	cam->upper_left_corner = vec_add(vec_add(vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length)), vec_div(cam->horizontal, -2)), vec_div(cam->vertical, -2));
	parameters = free_arr_null(parameters);
	orig = free_arr_null(orig);
	orientation = free_arr_null(orientation);
	print_object(cam, CAMERA);
	return (cam);
}

void	translate_camera(t_camera *cam, t_vec3 vec)
{
	cam->orig = vec_add(cam->orig, vec);
	cam->upper_left_corner = vec_add(vec_add(vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length)), vec_div(cam->horizontal, -2)), vec_div(cam->vertical, -2));
}
