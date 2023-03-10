#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_pt3
{
	float_t		x;
	float_t		y;
	float_t		z;
}			t_pt3;

typedef struct s_pt3	t_vec3;

typedef struct s_vec4
{
	float_t		x;
	float_t		y;
	float_t		z;
	float_t		a;
}			t_vec4;

#endif