#include "miniRT.h"

t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	sum;

	sum.x = vec1.x + vec2.x;
	sum.y = vec1.y + vec2.y;
	sum.z = vec1.z + vec2.z;
	return (sum);
}

t_vec3	vec_sub(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	diff;

	diff.x = vec1.x - vec2.x;
	diff.y = vec1.y - vec2.y;
	diff.z = vec1.z - vec2.z;
	return (diff);
}

t_vec3	vec_mult(t_vec3 vec, float_t factor)
{
	t_vec3	prod;

	prod.x = vec.x * factor;
	prod.y = vec.y * factor;
	prod.z = vec.z * factor;
	return (prod);
}

t_vec3	vec_div(t_vec3 vec, float_t factor)
{
	t_vec3	quotient;

	if (factor == 0)
	{
		ft_putstr_fd("WARNING: Dividing By 0\n", STDERR_FILENO);
		// Check here what we should really return (return ((t_vec3){0, 0, 0}));
	}
	quotient.x = vec.x / factor;
	quotient.y = vec.y / factor;
	quotient.z = vec.z / factor;
	return (quotient);
}