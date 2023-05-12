#include "miniRT.h"

float_t	random_float(void)
{
	float_t not_so_random;

	not_so_random = 0.5;
	return (not_so_random);
}

t_vec3	vector(float_t x, float_t y, float_t z)
{
	return ((t_vec3){x, y, z});
}

float_t	random_from(float_t min, float_t max)
{
	return (min + (max - min) * random_float());
}

t_vec3 random_vector_in(float_t min, float_t max)
{
    t_vec3 result;
    result.x = random_from(min, max);
    result.y = random_from(min, max);
    result.z = random_from(min, max);
    return result;
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	random;

	while (1)
	{
		random = random_vector_in(-1.0, 1.0);
		if (scalar_prod(random, random) >= 1)
			continue ;
		return (random);
	}
}
