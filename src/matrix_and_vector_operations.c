#include "miniRT.h"

t_vec3	mat_mult(t_mat3x3 mat, t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x * mat.c1r1 + vec.y * mat.c2r1 + vec.z * mat.c3r1;
	res.y = vec.x * mat.c1r2 + vec.y * mat.c2r2 + vec.z * mat.c3r2;
	res.z = vec.x * mat.c1r3 + vec.y * mat.c2r3 + vec.z * mat.c3r3;
	return (res);
}

t_mat3x3	mat3x3_dot_prod(t_mat3x3 a, t_mat3x3 b)
{
	t_mat3x3	res;

	res.c1r1 = b.c1r1 * a.c1r1 + b.c1r2 * a.c2r1 + b.c1r3 * a.c3r1;
	res.c1r2 = b.c1r1 * a.c1r2 + b.c1r2 * a.c2r2 + b.c1r3 * a.c3r2;
	res.c1r3 = b.c1r1 * a.c1r3 + b.c1r2 * a.c2r3 + b.c1r3 * a.c3r3;
	res.c2r1 = b.c2r1 * a.c1r1 + b.c2r2 * a.c2r1 + b.c2r3 * a.c3r1;
	res.c2r2 = b.c2r1 * a.c1r2 + b.c2r2 * a.c2r2 + b.c2r3 * a.c3r2;
	res.c2r3 = b.c2r1 * a.c1r3 + b.c2r2 * a.c2r3 + b.c2r3 * a.c3r3;
	res.c3r1 = b.c3r1 * a.c1r1 + b.c3r2 * a.c2r1 + b.c3r3 * a.c3r1;
	res.c3r2 = b.c3r1 * a.c1r2 + b.c3r2 * a.c2r2 + b.c3r3 * a.c3r2;
	res.c3r3 = b.c3r1 * a.c1r3 + b.c3r2 * a.c2r3 + b.c3r3 * a.c3r3;
	return (res);
}

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
		// Check here what we should really return
		return ((t_vec3){0, 0, 0});
	}
	quotient.x = vec.x / factor;
	quotient.y = vec.y / factor;
	quotient.z = vec.z / factor;
	return (quotient);
}

float_t	scalar_prod(t_vec3 vec1, t_vec3 vec2)
{
	float_t	prod;

	prod = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (prod);
}

t_vec3	cross_prod(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	prod;

	prod.x = vec1.y * vec2.z - vec1.z * vec2.y;
	prod.y = vec1.z * vec2.x - vec1.x * vec2.z;
	prod.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (prod);
}

float_t	vec_length(t_vec3 vec)
{
	float_t	length;

	length = sqrtf(scalar_prod(vec, vec));
	return (length);
}

t_vec3	unit_vec3(t_vec3 vec)
{
	t_vec3	unit;
	t_vec3	null_vec;

	null_vec = (t_vec3){0, 0, 0};
	if (vec_cmp(vec, null_vec) == 0)
		return (null_vec);
	unit = vec_div(vec, vec_length(vec));
	return (unit);
}

int		vec_cmp(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x != vec2.x)
		return (1);
	if (vec1.y != vec2.y)
		return (1);
	if (vec1.z != vec2.z)
		return (1);
	return (0);
}

t_vec4 vec4_mult(t_vec4 vec, float_t factor)
{
	t_vec4	prod;

	prod.x = vec.x * factor;
	prod.y = vec.y * factor;
	prod.z = vec.z * factor;
	prod.a = vec.a * factor;
	return (prod);
}

float_t clamp(float_t value, float_t min, float_t max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_vec4 vec4_clamp(t_vec4 vec, float_t min, float_t max)
{
	t_vec4	clamped;

	clamped.x = clamp(vec.x, min, max);
	clamped.y = clamp(vec.y, min, max);
	clamped.z = clamp(vec.z, min, max);
	clamped.a = clamp(vec.a, min, max);
	return (clamped);
}
