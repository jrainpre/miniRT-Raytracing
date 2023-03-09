#ifndef CAMERA_H
# define CAMERA_H

/*
◦ Camera:
C -50.0,0,20 0,0,1 70
∗ identifier: C
∗ x,y,z coordinates of the view point: -50.0,0,20
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
*/

#include "vector.h"

typedef struct s_camera {
	t_pt	orig;
	t_vec	orientation;
	float_t	fov;
	float_t	sensor_width;
	float_t	sensor_height;
	float_t	focal_length;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	lower_left_corner;
}	t_camera;

#endif