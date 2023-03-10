#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_ray
{
	t_pt3	orig;
	t_vec3	dir;
}	t_ray;

#endif