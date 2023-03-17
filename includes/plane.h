#ifndef PLANE_H
# define PLANE_H
/*
◦ Plane:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
∗ identifier: pl
∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
∗ R,G,B colors in range [0-255]: 0,0,225
*/

# include <math.h>
# include "vector.h"
# include "colors.h"

typedef struct s_plane {
	t_pt3	point;
	t_vec3	normal_vec;
	t_color	color;
}	t_plane;

typedef struct s_plane_hit_calc {
	float_t	numerator;
	float_t	denominator;
	float_t	distance_t;
}	t_plane_hit_calc;

#endif
