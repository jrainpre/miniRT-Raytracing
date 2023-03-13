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
# include "sphere.h"
# include "light.h"
# include "ray.h"
# include "miniRT.h"


typedef struct s_sphere {
	t_pt3 orig;
	float_t radius;
	t_color color;
} t_sphere;

typedef struct s_sphere_hit_calc {
	float_t a;
	float_t b;
	float_t c;
	float_t discriminant;
	float_t distance_t;
} t_sphere_hit_calc;




#endif
