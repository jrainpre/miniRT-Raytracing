#ifndef CYLINDER_H
# define CYLINDER_H
/*
◦ Cylinder:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
∗ identifier: cy
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255
*/

# include <math.h>
# include "vector.h"
# include "colors.h"

typedef struct s_cylinder {
	t_pt3	orig;
	t_vec3	axis;
	float_t	radius;
	float_t	height;
	t_color	color;
}	t_cylinder;

#endif