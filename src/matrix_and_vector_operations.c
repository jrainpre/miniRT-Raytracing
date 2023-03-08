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
