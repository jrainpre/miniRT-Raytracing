#include "miniRT.h"

void	get_closest_hit(t_scene *scene, t_ray ray, t_hit_info *hit_info)
{
	t_lst		*list;
	t_lst		*closest_hit;
	float_t		closest_t;
	float_t		distance_t;

	closest_t = INFINITY;
	hit_info->object = NULL;
	list = scene->objects->head;
	while (list)
	{
		distance_t = get_distance_t(list, ray);
		if (distance_t > 0.0f && distance_t < closest_t)
		{
			closest_t = distance_t;
			hit_info->object = list;
			hit_info->ray = ray;
		}
		list = list->next;
	}
	hit_info->distance = closest_t;
}

int	is_in_fornt_of_light(t_scene *scene, t_ray ray, float_t distance_t)
{
	t_vec3	hit_to_light;
	t_vec3	light_direction;

	light_direction = unit_vec3(vec_sub(scene->light->orig, ray.orig));
	hit_to_light = vec_sub(scene->light->orig, \
		vec_add(ray.orig, vec_mult(ray.dir, distance_t)));
	if (scalar_prod(light_direction, hit_to_light) >= 0)
		return (1);
	return (0);
}

t_lst	*get_closest_hit_light(t_scene *scene, t_ray ray)
{
	t_lst	*list;
	t_lst	*closest_hit;
	float_t	distance_t;
	float_t	closest_t;

	closest_t = INFINITY;
	closest_hit = NULL;
	list = scene->objects->head;
	while (list)
	{
		distance_t = get_distance_t(list, ray);
		if (distance_t > 0.0f && distance_t < closest_t)
		{
			if (is_in_fornt_of_light(scene, ray, distance_t))
			{
				closest_t = distance_t;
				closest_hit = list;
			}
		}
		list = list->next;
	}
	return (closest_hit);
}

float_t	get_distance_t(t_lst *object, t_ray ray)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_sphere_distance_t(object, ray));
	else if (type == PLANE)
		return (get_plane_distance_t(object, ray));
	else if (type == CYLINDER)
		return (get_cylinder_distance_t((t_cylinder *)object->content, ray));
	return (INFINITY);
}

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

float_t	get_sphere_distance_t(t_lst *object, t_ray ray)
{
	t_hit_calc	calc;
	t_vec3		orig_diff;
	t_sphere	*sphere;

	sphere = (t_sphere *)object->content;
	orig_diff = vec_sub(ray.orig, sphere->orig);
	calc.a = scalar_prod(ray.dir, ray.dir);
	calc.b = 2.0 * scalar_prod(orig_diff, ray.dir);
	calc.c = \
		scalar_prod(orig_diff, orig_diff) - sphere->radius * sphere->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (0);
	if (calc_distant_t(&calc) == -1)
		return (0);
	return (calc.distance_t);
}

t_color	light_shade_object(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_color	color;

	color = get_color_hitpoint(scene, object, hit_info);
	return (color);
}

void	get_hitpoint_object(t_lst *object, t_hit_info *hit_info)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		get_hitpoint_sphere(object, hit_info);
	else if (type == PLANE)
		get_hitpoint_plane(object, hit_info);
	else if (type == CYLINDER)
		get_hitpoint_cylinder(object, hit_info);
	else
		hit_info->hitpoint = (t_vec3){0, 0, 0};
}

void	get_hitpoint_cylinder(t_lst *object, t_hit_info *hit_info)
{
	t_vec3		hit_point;
	t_vec3		temp;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object->content;
	(void)cylinder;
	temp = vec_mult(hit_info->ray.dir, hit_info->distance);
	hit_info->hitpoint = vec_add(temp, hit_info->ray.orig);
}

void	get_hitpoint_sphere(t_lst *object, t_hit_info *hit_info)
{
	t_vec3		hit_point;
	t_vec3		temp;
	t_sphere	*sphere;

	sphere = (t_sphere *)object->content;
	(void)sphere;
	temp = vec_mult(hit_info->ray.dir, hit_info->distance);
	hit_info->hitpoint = vec_add(temp, hit_info->ray.orig);
}

t_color	get_color_hitpoint(t_scene *scene, t_lst *object, t_hit_info *hit_info)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	result;

	if (object->is_slected)
		return ((t_color){1.0f, 0.0f, 0.0f});
	ambient = get_ambient_color_object(scene, object);
	diffuse = get_diffuse_color_object(scene, object, hit_info);
	specular = get_specular_color_object(scene, object, hit_info);
	result = color_add(ambient, diffuse);
	result = color_add(result, specular);
	result = color_clamp(result, 0.0f, 1.0f);
	return (result);
}	

float_t	get_light_angle(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3	unit_light;
	t_vec3	normal_hit_point;
	t_vec3	unit_normal_hit_point;
	float_t	angle;

	normal_hit_point = vec_sub(hit_point, sphere->orig);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

float_t	get_light_angle_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene)
{
	t_vec3	unit_light;
	t_vec3	normal_hit_point;
	t_vec3	unit_normal_hit_point;
	float_t	angle;

	(void)hit_point;
	normal_hit_point = vec_mult(plane->normal_vec, -1);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

void	normal_cyl_proj(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	projection;
	t_vec3	projected_point;
	t_lst	object;
	float_t	distance_t;
	t_vec3	temp;

	temp = vec_sub(hit_info->hitpoint, cylinder->orig);
	projection = scalar_prod(temp, cylinder->axis);
	distance_t = get_cylinder_distance_t_proj(cylinder, hit_info->ray);
	if (fabs(hit_info->distance - distance_t) < 0.001)
	{
		temp = vec_mult(cylinder->axis, projection);
		projected_point = vec_add(cylinder->orig, temp);
		hit_info->normal = vec_sub(hit_info->hitpoint, projected_point);
		hit_info->normal = unit_vec3(hit_info->normal);
	}
}

void	normal_cyl_top_cap(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	distance_t;

	distance_t = find_top_cap_intersection(cylinder, hit_info->ray);
	if (fabs(hit_info->distance - distance_t) < 0.001)
		hit_info->normal = cylinder->axis;
}

void	normal_cyl_bottom_cap(t_hit_info *hit_info, t_cylinder *cylinder)
{
	float_t	distance_t;

	distance_t = find_bottom_cap_intersection(cylinder, hit_info->ray);
	if (fabs(hit_info->distance - distance_t) < 0.001)
		hit_info->normal = vec_mult(cylinder->axis, -1);
}

void	get_normal_cylinder(t_hit_info *hit_info, t_cylinder *cylinder)
{
	normal_cyl_proj(hit_info, cylinder);
	normal_cyl_top_cap(hit_info, cylinder);
	normal_cyl_bottom_cap(hit_info, cylinder);
}

float_t	get_light_angle_cyl(t_hit_info *hit_info, t_cylinder *cyl, \
	t_scene *scene)
{
	t_vec3	unit_light;
	float_t	angle;

	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(hit_info->normal, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

int	calc_distant_t(t_hit_calc *calc)
{
	float_t	t1;
	float_t	t2;
	float_t	smallest_t;

	t1 = (-calc->b - sqrt(calc->discriminant)) / (2.0f * calc->a);
	t2 = (-calc->b + sqrt(calc->discriminant)) / (2.0f * calc->a);
	smallest_t = fmin(t1, t2);
	calc->distance_t = smallest_t;
	if (calc->distance_t < 0)
		return (-1);
	return (0);
}
