#include "miniRT.h"

float_t	get_cylinder_distance_t_proj(t_cylinder *cylinder, t_ray ray)
{
	t_hit_calc	calc;
	t_vec3		orig_diff;

	orig_diff = vec_sub(ray.orig, cylinder->orig);
	calc.a = scalar_prod(ray.dir, ray.dir) \
		- pow(scalar_prod(ray.dir, cylinder->axis), 2);
	calc.b = 2 * (scalar_prod(ray.dir, orig_diff) \
		- scalar_prod(ray.dir, cylinder->axis) \
		* scalar_prod(orig_diff, cylinder->axis));
	calc.c = scalar_prod(orig_diff, orig_diff) \
		- pow(scalar_prod(orig_diff, cylinder->axis), 2) \
		- cylinder->radius * cylinder->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0 || calc_distant_t(&calc) == -1)
		return (0);
	return (calc.distance_t);
}

float_t	find_top_cap_intersection(t_cylinder *cylinder, t_ray ray)
{
	t_vec3	cap_top_cent;
	float_t	t_cap_top;
	t_vec3	cap_top_intersection;
	float_t	cap_top_dist;

	cap_top_cent = vec_add(cylinder->orig, \
		vec_mult(cylinder->axis, cylinder->height));
	t_cap_top = (scalar_prod(vec_sub(cap_top_cent, ray.orig), \
		cylinder->axis)) / scalar_prod(ray.dir, cylinder->axis);
	if (t_cap_top > FLT_EPSILON)
	{
		cap_top_intersection = vec_add(ray.orig, vec_mult(ray.dir, t_cap_top));
		cap_top_dist = vec_length(vec_sub(cap_top_intersection, cap_top_cent));
		if (cap_top_dist <= cylinder->radius)
			return (t_cap_top);
	}
	return (0);
}

float_t	find_bottom_cap_intersection(t_cylinder *cylinder, t_ray ray)
{
	t_vec3	cap_bot_cent;
	float_t	t_cap_bot;
	t_vec3	cap_bot_intersection;
	float_t	cap_bot_dist;

	cap_bot_cent = cylinder->orig;
	t_cap_bot = (scalar_prod(vec_sub(cap_bot_cent, ray.orig), \
		cylinder->axis)) / scalar_prod(ray.dir, cylinder->axis);
	if (t_cap_bot > FLT_EPSILON)
	{
		cap_bot_intersection = vec_add(ray.orig, vec_mult(ray.dir, t_cap_bot));
		cap_bot_dist = vec_length(vec_sub(cap_bot_intersection, cap_bot_cent));
		if (cap_bot_dist <= cylinder->radius)
			return (t_cap_bot);
	}
	return (0);
}

float_t	get_cylinder_distance_t(t_cylinder *cylinder, t_ray ray)
{
	float_t	distance_t;
	float_t	intersect;
	float_t	cap_intersect;
	t_vec3	point;
	float_t	proj;

	distance_t = get_cylinder_distance_t_proj(cylinder, ray);
	intersect = 0;
	point = vec_add(ray.orig, vec_mult(ray.dir, distance_t));
	proj = scalar_prod(vec_sub(point, cylinder->orig), cylinder->axis);
	cap_intersect = find_bottom_cap_intersection(cylinder, ray);
	if (cap_intersect > 0 && (intersect == 0 || cap_intersect < intersect))
		intersect = cap_intersect;
	cap_intersect = find_top_cap_intersection(cylinder, ray);
	if (cap_intersect > 0 && (intersect == 0 || cap_intersect < intersect))
		intersect = cap_intersect;
	if (proj >= 0 && proj <= cylinder->height && distance_t > 0)
		intersect = distance_t;
	return (intersect);
}