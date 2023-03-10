#include "miniRT.h"

t_camera	*init_camera(t_camera *cam, t_resolution win)
{
	cam = malloc_or_print_error(sizeof (t_camera));
	if (cam == NULL)
		return (NULL);
	cam->orig = (t_pt3){0, 0, 10};
	cam->orientation = (t_vec3){0, 0, -1};
	cam->fov = 70;
	cam->sensor_height = 2;
	cam->sensor_width = ((float_t)win.width / (float_t)win.height) * cam->sensor_height;
	cam->focal_length = (cam->sensor_width / 2) / tanf(deg_to_rad(cam->fov / 2.0));
	cam->vertical = (t_vec3){0, -cam->sensor_height, 0};
	cam->horizontal = (t_vec3){cam->sensor_width, 0, 0};
	cam->upper_left_corner = vec_add(vec_add(vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length)), vec_div(cam->horizontal, -2)), vec_div(cam->vertical, -2));
	return (cam);
}

void	translate_camera(t_camera *cam, t_vec3 vec)
{
	cam->orig = vec_add(cam->orig, vec);
	cam->upper_left_corner = vec_add(vec_add(vec_add(cam->orig, vec_mult(cam->orientation, cam->focal_length)), vec_div(cam->horizontal, -2)), vec_div(cam->vertical, -2));
}
