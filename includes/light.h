#ifndef LIGHT_H
# define LIGHT_H

/*
Light:
L -40.0,50.0,0.0 0.6 10,0,255
∗ identifier: L
∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
∗ the light brightness ratio in range [0.0,1.0]: 0.6
∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/

#include "colors.h"
#include "vector.h"

typedef struct s_light {
	t_pt3 orig;
	float_t ratio;
	t_color color;
} t_light;

#endif
