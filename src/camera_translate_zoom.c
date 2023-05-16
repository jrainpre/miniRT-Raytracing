#include "miniRT.h"

void	translate_camera(t_camera *cam, t_vec3 vec)
{
	cam->orig = vec_add(cam->orig, vec);
	cam->upper_left_corner = calc_upper_left_corner(cam);
}

void	zoom_in(t_camera *cam, float_t focal_length)
{
	cam->focal_length += focal_length;
	cam->upper_left_corner = calc_upper_left_corner(cam);
}

void	zoom_out(t_camera *cam, float_t focal_length)
{
	cam->focal_length -= focal_length;
	if (cam->focal_length < 0)
		cam->focal_length = 0;
	cam->upper_left_corner = calc_upper_left_corner(cam);
}
