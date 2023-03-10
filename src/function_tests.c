#include "miniRT.h"

void	vector_test(void)
{
	t_vec3	vec1;
	t_vec3	vec2;
	t_vec3	res;
	float_t	factor;
	float_t	scalar_res;
	float_t	length;

	vec1 = (t_vec3){1, 2, 0};
	vec2 = (t_vec3){0, 3, 1};
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

	length = vec_length(vec1);
	printf("|vec1|\n");
	printf("length: %19.15f\n", length);
	printf("\n");

	res = unit_vec3(vec1);
	printf("unit vector of vec1\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}

void	ray_test(void)
{
	t_ray	ray;
	t_vec3	dir;
	t_pt3	res;
	float_t	t;

	dir = (t_vec3){1, 0, 0};
	ray.orig = (t_pt3){100, 0, 0};
	ray.dir = dir;
	t = -100;

	printf("ray.orig\n");
	printf("x: %19.15f\n", ray.orig.x);
	printf("y: %19.15f\n", ray.orig.y);
	printf("z: %19.15f\n", ray.orig.z);
	printf("\n");

	printf("ray.dir\n");
	printf("x: %19.15f\n", ray.dir.x);
	printf("y: %19.15f\n", ray.dir.y);
	printf("z: %19.15f\n", ray.dir.z);
	printf("\n");

	printf("t: %19.15f\n", t);
	printf("\n");

	res = ray_point_at(ray, t);
	printf("P(t) = ray.orig + t * ray.dir\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}
