#include "miniRT.h"

t_vec3	get_hitpoint_plane(t_lst *object, float_t distance_t, t_ray ray)
{
	t_vec3	hit_point;
	t_plane	*plane;

	plane = (t_plane *)object->content;
	hit_point = vec_add(vec_mult(ray.dir, distance_t), ray.orig);
	return (hit_point);
}

float_t	get_plane_distance_t(t_lst *object, t_ray ray)
{
	t_plane_hit_calc	calc;	
	t_vec3				ray_plane_diff;
	t_plane				*plane;
	float_t				dir_len;

	plane = (t_plane *)object->content;
	calc.denominator = scalar_prod(unit_vec3(ray.dir), plane->normal_vec);
	dir_len = vec_length(ray.dir);
	if (calc.denominator > FLT_EPSILON)
	{
		ray_plane_diff = vec_sub(plane->point, ray.orig);
		calc.numerator = scalar_prod(ray_plane_diff, plane->normal_vec);
		calc.distance_t = calc.numerator / calc.denominator;
		calc.distance_t /= dir_len;
		if (calc.distance_t >= 0)
			return (calc.distance_t);
	}
	return (-1);
}

int	hit_plane(t_plane *plane, t_ray ray, t_scene *scene)
{
	t_plane_hit_calc	calc;	
	t_vec3				ray_plane_diff;

	(void)scene;
	calc.denominator = scalar_prod(unit_vec3(ray.dir), plane->normal_vec);
	if (calc.denominator > FLT_EPSILON)
	{
		ray_plane_diff = vec_sub(plane->point, ray.orig);
		calc.numerator = scalar_prod(ray_plane_diff, plane->normal_vec);
		calc.distance_t = calc.numerator / calc.denominator;
		if (calc.distance_t >= 0)
			return (color_conversion(plane->color));
	}
	return (-1);
}
