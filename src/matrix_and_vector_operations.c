#include "miniRT.h"

t_vec	mat_mult(t_mat3x3 mat, t_vec vec)
{
	t_vec	res;

	res.x = vec.x * mat.c1r1 + vec.y * mat.c2r1 + vec.z * mat.c3r1;
	res.y = vec.x * mat.c1r2 + vec.y * mat.c2r2 + vec.z * mat.c3r2;
	res.z = vec.x * mat.c1r3 + vec.y * mat.c2r3 + vec.z * mat.c3r3;
	res.color = vec.color;
	return (res);
}

t_vec	vec_add(t_vec vec1, t_vec vec2)
{
	t_vec	sum;

	sum.x = vec1.x + vec2.x;
	sum.y = vec1.y + vec2.y;
	sum.z = vec1.z + vec2.z;
	sum.color = vec1.color;
	return (sum);
}

t_vec	vec_sub(t_vec vec1, t_vec vec2)
{
	t_vec	diff;

	diff.x = vec1.x - vec2.x;
	diff.y = vec1.y - vec2.y;
	diff.z = vec1.z - vec2.z;
	diff.color = vec1.color;
	return (diff);
}

t_vec	vec_mult(t_vec vec, float_t factor)
{
	t_vec	prod;

	prod.x = vec.x * factor;
	prod.y = vec.y * factor;
	prod.z = vec.z * factor;
	prod.color = vec.color;
	return (prod);
}

t_vec	vec_div(t_vec vec, float_t factor)
{
	t_vec	quotient;

	if (factor == 0)
	{
		ft_putstr_fd("WARNING: Dividing By 0\n", STDERR_FILENO);
		return ((t_vec){0, 0, 0, 0});
	}
	quotient.x = vec.x / factor;
	quotient.y = vec.y / factor;
	quotient.z = vec.z / factor;
	quotient.color = vec.color;
	return (quotient);
}

float_t	scalar_prod(t_vec vec1, t_vec vec2)
{
	float_t	prod;

	prod = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (prod);
}

t_vec	cross_prod(t_vec vec1, t_vec vec2)
{
	t_vec	prod;

	prod.x = vec1.y * vec2.z - vec1.z * vec2.y;
	prod.y = vec1.z * vec2.x - vec1.x * vec2.z;
	prod.z = vec1.x * vec2.y - vec1.y * vec2.x;
	prod.color = vec1.color;
	return (prod);
}

float_t	vec_length(t_vec vec)
{
	float_t	length;

	length = sqrtf(scalar_prod(vec, vec));
	return (length);
}

t_vec	unit_vec(t_vec vec)
{
	t_vec	unit;
	t_vec	null_vec;

	null_vec = (t_vec){0, 0, 0, 0};
	if (vec_cmp(vec, null_vec) == 0)
		return (null_vec);
	unit = vec_div(vec, vec_length(vec));
	return (unit);
}

int		vec_cmp(t_vec vec1, t_vec vec2)
{
	if (vec1.x != vec2.x)
		return (1);
	if (vec1.y != vec2.y)
		return (1);
	if (vec1.z != vec2.z)
		return (1);
	if (vec1.color != vec2.color)
		return (1);
	return (0);
}
