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
	t_pt3	orig;
	t_vec3	orientation;
	t_vec3	left;
	t_vec3	up;
	float_t	rot_y_angle;
	float_t	rot_x_angle;
	float_t	fov;
	float_t	sensor_width;
	float_t	sensor_height;
	float_t	focal_length;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	upper_left_corner;
}	t_camera;

#endif