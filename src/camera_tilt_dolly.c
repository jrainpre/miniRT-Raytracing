#include "miniRT.h"

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
