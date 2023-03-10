#include "miniRT.h"

t_pt3	ray_point_at(t_ray ray, float_t t)
{
	t_pt3	point;

	point = vec_add(ray.orig, vec_mult(ray.dir, t));
	return (point);
}
