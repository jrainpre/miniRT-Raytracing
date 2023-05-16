#include "miniRT.h"

void	pan_left(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, angle);
}

void	pan_right(t_camera *cam, float_t angle)
{
	rotate_y_camera(cam, -angle);
}
