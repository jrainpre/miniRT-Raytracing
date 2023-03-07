#ifndef SPHERE_H
#define SPHERE_H

// ◦ Sphere:
// sp 0.0,0.0,20.6 12.6 10,0,255
// ∗ identifier: sp
// ∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
// ∗ the sphere diameter: 12.6
// ∗ R,G,B colors in range [0-255]: 10, 0, 255

#include <math.h>
#include "vector.h"
#include "colors.h"


typedef struct s_sphere {
	t_pt orig;
	float radius;
	t_color color;
} t_sphere;



#endif
