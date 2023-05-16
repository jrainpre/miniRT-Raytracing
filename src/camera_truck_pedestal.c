#include "miniRT.h"

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
