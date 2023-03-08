#include "miniRT.h"

t_pt	ray_point_at(t_ray ray, float_t t)
{
	t_pt	point;

	point = vec_add(ray.orig, vec_mult(ray.dir, t));
	return (point);
}
