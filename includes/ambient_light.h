#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
/*
Ambient lightning:
A 0.2 255,255,255
∗ identifier: A
∗ ambient lighting ratio in range [0.0,1.0]: 0.2
∗ R,G,B colors in range [0-255]: 255, 255, 255
*/

#include "colors.h"
#include "vector.h"

typedef struct s_ambient_light {
	float_t ratio;
	t_color color;
} t_ambient_light;

#endif
