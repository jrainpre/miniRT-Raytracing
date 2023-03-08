#include "miniRT.h"

void	vector_test(void)
{
	t_vec	vec1;
	t_vec	vec2;
	t_vec	res;
	float_t	factor;
	float_t	scalar_res;

	vec1 = (t_vec){1, 0, 0, NOCOLOR};
	vec2 = (t_vec){0, 0, 1, NOCOLOR};
	factor = 2;
	printf("vec1\n");
	printf("x: %19.15f\n", vec1.x);
	printf("y: %19.15f\n", vec1.y);
	printf("z: %19.15f\n", vec1.z);
	printf("\n");

	printf("vec2\n");
	printf("x: %19.15f\n", vec2.x);
	printf("y: %19.15f\n", vec2.y);
	printf("z: %19.15f\n", vec2.z);
	printf("\n");

	printf("factor: %19.15f\n", factor);
	printf("\n");

	res = vec_add(vec1, vec2);
	printf("vec1 + vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_sub(vec1, vec2);
	printf("vec1 - vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_mult(vec1, factor);
	printf("vec1 * factor\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_div(vec1, factor);
	printf("vec1 / factor\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	scalar_res = scalar_prod(vec1, vec2);
	printf("vec1 * vec2\n");
	printf("scalar_res: %19.15f\n", scalar_res);
	printf("\n");

	res = cross_prod(vec1, vec2);
	printf("vec1 x vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}