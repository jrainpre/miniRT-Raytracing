#include "miniRT.h"

t_lst	*get_closest_hit(t_scene *scene, t_ray ray)
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
			closest_t = distance_t;
			closest_hit = list;
		}
		list = list->next;
	}
	return (closest_hit);
}

t_lst	*get_closest_hit_light(t_scene *scene, t_ray ray)
{
	t_lst	*list;
	t_lst	*closest_hit;
	float_t	distance_t;
	float_t	closest_t;
	t_vec3	light_direction;
	t_vec3	hit_to_light;

	closest_t = INFINITY;
	closest_hit = NULL;
	light_direction = unit_vec3(vec_sub(scene->light->orig, ray.orig));
	list = scene->objects->head;
	while (list)
	{
		distance_t = get_distance_t(list, ray);
		if (distance_t > 0.0f && distance_t < closest_t)
		{
			hit_to_light = vec_sub(scene->light->orig, vec_add(ray.orig, vec_mult(ray.dir, distance_t)));
			if (scalar_prod(light_direction, hit_to_light) >= 0)
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
		return (get_cylinder_distance_t(object, ray));
	return (INFINITY);
}


float_t get_cylinder_distance_t_proj(t_lst *object, t_ray ray)
{
	t_hit_calc	calc;
	t_vec3	orig_diff;
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)object->content;
	orig_diff = vec_sub(ray.orig, cylinder->orig);
	calc.a = scalar_prod(ray.dir, ray.dir) - pow(scalar_prod(ray.dir, cylinder->axis), 2);
	calc.b = 2 * (scalar_prod(ray.dir, orig_diff) - scalar_prod(ray.dir, cylinder->axis) * scalar_prod(orig_diff, cylinder->axis));
	calc.c = scalar_prod(orig_diff, orig_diff) - pow(scalar_prod(orig_diff, cylinder->axis), 2) - cylinder->radius * cylinder->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (0);
	if (calc_distant_t(&calc) == -1)
		return (0);
	return (calc.distance_t);
}



// float_t	get_plane_distance_t(t_lst *object, t_ray ray)
// {
// 	t_plane_hit_calc	calc;	
// 	t_vec3				ray_plane_diff;
// 	t_plane				*plane;
// 	float_t				dir_len;

// 	plane = (t_plane *)object->content;
// 	calc.denominator = scalar_prod(unit_vec3(ray.dir), plane->normal_vec);
// 	dir_len = vec_length(ray.dir);
// 	if (calc.denominator > FLT_EPSILON)
// 	{
// 		ray_plane_diff = vec_sub(plane->point, ray.orig);
// 		calc.numerator = scalar_prod(ray_plane_diff, plane->normal_vec);
// 		calc.distance_t = calc.numerator / calc.denominator;
// 		calc.distance_t /= dir_len;
// 		if (calc.distance_t >= 0)
// 			return (calc.distance_t);
// 	}
// 	return (-1);
// }


// float_t find_top_cap_intersection(t_cylinder *cylinder, t_ray ray)
// {
//     t_vec3 cap_top_center;
//     float_t t_cap_top;
//     t_vec3 cap_top_intersection;
//     float_t cap_top_dist;
// 	float_t test;
// 	t_plane_hit_calc	calc;
// 	t_vec3				ray_plane_diff;
// 	float_t				dir_len;




// 	calc.denominator = scalar_prod(unit_vec3(ray.dir), vec_mult(cylinder->axis, -1));
//     cap_top_center = vec_add(cylinder->orig, vec_mult(cylinder->axis, cylinder->height));
// 	dir_len = vec_length(ray.dir);

    
// 	if (calc.denominator > FLT_EPSILON)
// 	{
// 		ray_plane_diff = vec_sub(cap_top_center, ray.orig);
// 		calc.numerator = scalar_prod(ray_plane_diff, vec_mult(cylinder->axis, -1));
// 		calc.distance_t = calc.numerator / calc.denominator;
// 		calc.distance_t /= dir_len;
//         if (calc.distance_t >= 0)
//         {
//             cap_top_intersection = vec_add(ray.orig, vec_mult(ray.dir, calc.distance_t));
//             cap_top_dist = vec_length(vec_sub(cap_top_intersection, cap_top_center));
//             if (cap_top_dist < cylinder->radius)
//                 return calc.distance_t;
//         }
// 	}
// 	return (0);
// }

float_t find_top_cap_intersection(t_lst *object, t_ray ray)
{
	t_vec3 cap_top_center;
	float_t t_cap_top;
	t_vec3 cap_top_intersection;
	float_t cap_top_dist;
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)object->content;
	cap_top_center = vec_add(cylinder->orig, vec_mult(cylinder->axis, cylinder->height));
	t_cap_top = (scalar_prod(vec_sub(cap_top_center, ray.orig), cylinder->axis)) / scalar_prod(ray.dir, cylinder->axis);
	cap_top_intersection = vec_add(ray.orig, vec_mult(ray.dir, t_cap_top));
	cap_top_dist = vec_length(vec_sub(cap_top_intersection, cap_top_center));
	if (cap_top_dist <= cylinder->radius && t_cap_top > 0)
		return (t_cap_top);
    return (INFINITY);
}
// float_t find_top_cap_intersection(t_cylinder *cylinder, t_ray ray)
// {
//     t_vec3 cap_top_center;
//     t_vec3 cap_top_intersection;
//     float_t cap_top_dist;
//     t_plane_hit_calc calc;
//     t_vec3 ray_plane_diff;
//     float_t dir_len;

//     calc.denominator = scalar_prod(unit_vec3(ray.dir), vec_mult(cylinder->axis, -1));
//     cap_top_center = vec_add(cylinder->orig, vec_mult(cylinder->axis, cylinder->height));
    
//     if (calc.denominator > FLT_EPSILON)
//     {
//         ray_plane_diff = vec_sub(cap_top_center, ray.orig);
//         calc.numerator = scalar_prod(ray_plane_diff, vec_mult(cylinder->axis, -1));
//         dir_len = vec_length(ray.dir);
//         calc.distance_t = calc.numerator / calc.denominator;
//         // calc.distance_t /= dir_len;

//         if (calc.distance_t >= 0)
//         {
//             cap_top_intersection = vec_add(ray.orig, vec_mult(ray.dir, calc.distance_t));
//             cap_top_dist = vec_length(vec_sub(cap_top_intersection, cap_top_center));

//             if (cap_top_dist < cylinder->radius)
//                 return calc.distance_t;
//         }
//     }
//     return 0;
// }

float_t find_bottom_cap_intersection(t_cylinder *cylinder, t_ray ray)
{
    t_vec3 cap_bottom_center;
    float_t t_cap_bottom;
    t_vec3 cap_bottom_intersection;
    float_t cap_bottom_dist;

    cap_bottom_center = cylinder->orig;
    t_cap_bottom = (scalar_prod(vec_sub(cap_bottom_center, ray.orig), cylinder->axis)) / scalar_prod(ray.dir, cylinder->axis);

    if (t_cap_bottom > FLT_EPSILON)
    {
        cap_bottom_intersection = vec_add(ray.orig, vec_mult(ray.dir, t_cap_bottom));
        cap_bottom_dist = vec_length(vec_sub(cap_bottom_intersection, cap_bottom_center));
        if (cap_bottom_dist <= cylinder->radius)
            return t_cap_bottom;
    }
    return 0;
}

float_t get_cylinder_distance_t(t_lst *object, t_ray ray)
{
	float_t distance_t;
	t_cylinder *cylinder;
	float_t intersect;
	float_t bottom_cap_intersect;
	float_t top_cap_intersect;
	t_vec3 point0;
	float_t proj0;

	cylinder = (t_cylinder *)object->content;
	distance_t = get_cylinder_distance_t_proj(object, ray);
	intersect = 0;
	point0 = vec_add(ray.orig, vec_mult(ray.dir, distance_t));
	proj0 = scalar_prod(vec_sub(point0, cylinder->orig), cylinder->axis);
	bottom_cap_intersect = find_bottom_cap_intersection(cylinder, ray);
	top_cap_intersect = find_top_cap_intersection(object, ray);
	if (bottom_cap_intersect > 0 && (intersect == 0 || bottom_cap_intersect < intersect))
		intersect = bottom_cap_intersect;
	if (top_cap_intersect > 0 && (intersect == 0 || top_cap_intersect < intersect))
		intersect = top_cap_intersect;
	if (proj0 >= 0 && proj0 <= cylinder->height &&  distance_t > 0)
				intersect = distance_t;
	return intersect;
}


float_t get_sphere_distance_t(t_lst *object, t_ray ray)
{
	t_hit_calc	calc;
	t_vec3	orig_diff;
	t_sphere *sphere;

	sphere = (t_sphere *)object->content;
	orig_diff = vec_sub(ray.orig, sphere->orig);
	calc.a = scalar_prod(ray.dir, ray.dir);
	calc.b = 2.0 * scalar_prod(orig_diff, ray.dir);
	calc.c = scalar_prod(orig_diff, orig_diff) - sphere->radius * sphere->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (0);
	if (calc_distant_t(&calc) == -1)
		return (0);
	return (calc.distance_t);
}

t_color light_shade_object(t_scene *scene, t_lst *object, t_ray ray)
{
	t_vec3 hit_point;
	float_t distance_t;
	t_color color;

	distance_t = get_distance_t(object, ray);
	hit_point = get_hitpoint_object(object, distance_t, ray);
	color = get_color_hitpoint(scene, object, ray, hit_point);

	return (color);
}

t_vec3 get_hitpoint_object(t_lst *object, float_t distance_t, t_ray ray)
{
	t_object_type	type;

	type = object->type;
	if (type == SPHERE)
		return (get_hitpoint_sphere(object, distance_t, ray));
	else if (type == PLANE)
		return (get_hitpoint_plane(object, distance_t, ray));
	else if (type == CYLINDER)
		return (get_hitpoint_cylinder(object, distance_t, ray));
	return ((t_vec3){0, 0, 0});
}

t_vec3 get_hitpoint_cylinder(t_lst *object, float_t distance_t, t_ray ray)
{
	t_vec3 hit_point;
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)object->content;
	(void)cylinder;
	hit_point = vec_add(vec_mult(ray.dir, distance_t), ray.orig);
	return (hit_point);
}

t_vec3 get_hitpoint_sphere(t_lst *object, float_t distance_t, t_ray ray)
{
	t_vec3 hit_point;
	t_sphere *sphere;

	sphere = (t_sphere *)object->content;
	(void)sphere;
	hit_point = vec_add(vec_mult(ray.dir, distance_t), ray.orig);
	return (hit_point);
}

t_color get_color_hitpoint(t_scene *scene, t_lst *object, t_ray ray, t_vec3 hitpoint)
{
	t_color ambient;
	t_color diffuse;
	t_color specular;
	t_color result;

	if (object->is_slected)
		return ((t_color){1.0f, 0.0f, 0.0f});
	ambient = get_ambient_color_object(scene, object);
	diffuse = get_diffuse_color_object(scene, object, hitpoint, ray);
	specular = get_specular_color_object(scene, object, hitpoint, ray);
	result = color_add(ambient, diffuse);
	result = color_add(result, specular);
	result = color_clamp(result, 0.0f, 1.0f);
	return (result);

}	

float_t get_light_angle(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3 unit_light;
	t_vec3 normal_hit_point;
	t_vec3 unit_normal_hit_point;
	float_t angle;

	normal_hit_point = vec_sub(hit_point, sphere->orig);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

float_t get_light_angle_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene)
{
	t_vec3 unit_light;
	t_vec3 normal_hit_point;
	t_vec3 unit_normal_hit_point;
	float_t angle;

	(void)hit_point;
	normal_hit_point = vec_mult(plane->normal_vec, -1);
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	unit_light = unit_vec3(scene->light->orig);
	angle = scalar_prod(unit_normal_hit_point, unit_light);
	angle = fmax(angle, 0.0f);
	return (angle);
}

// float_t get_light_angle_cylinder(t_vec3 hit_point, t_cylinder *cylinder, t_scene *scene)
// {
// 	t_vec3 unit_light;
// 	t_vec3 normal_hit_point;
// 	t_vec3 unit_normal_hit_point;
// 	float_t angle;

// 	(void)hit_point;
// 	normal_hit_point = vec_mult(cylinder->axis, 1);
// 	unit_normal_hit_point = unit_vec3(normal_hit_point);
// 	unit_light = unit_vec3(scene->light->orig);
// 	angle = scalar_prod(unit_normal_hit_point, unit_light);
// 	angle = fmax(angle, 0.0f);
// 	return (angle);
// }


// float_t get_light_angle_cylinder(t_vec3 hit_point, t_cylinder *cylinder, t_scene *scene, t_ray ray)
// {
// 	t_vec3 unit_light;
// 	t_vec3 normal_hit_point;
// 	t_vec3 unit_normal_hit_point;
// 	float_t angle;
// 	float_t projection;
// 	t_vec3 projected_point;
// 	float_t bottom;
// 	float_t top;
// 	float_t intersect;

// 	(void)ray;

// 	normal_hit_point = vec_sub(hit_point, cylinder->orig);
// 	projection = scalar_prod(normal_hit_point, cylinder->axis);
// 	if (projection > 0 && projection < cylinder->height)
// 	{
// 		projected_point = vec_add(cylinder->orig, vec_mult(cylinder->axis, projection));
// 		normal_hit_point = vec_sub(hit_point, projected_point);
// 	}
// 	 if (projection >= cylinder->height)
// 		normal_hit_point = cylinder->axis;
// 	if (projection < 0)
// 		normal_hit_point = vec_mult(cylinder->axis, -1.0f);

// 	unit_normal_hit_point = unit_vec3(normal_hit_point);
// 	unit_light = unit_vec3(scene->light->orig);
// 	angle = scalar_prod(unit_normal_hit_point, unit_light);
// 	angle = fmax(angle, 0.0f);
// 	return (angle);
// }



float_t get_light_angle_cylinder(t_vec3 hit_point, t_cylinder *cylinder, t_scene *scene, t_ray ray)
{
    t_vec3 unit_light;
    t_vec3 normal_hit_point;
    t_vec3 unit_normal_hit_point;
    float_t angle;
    float_t projection;
    t_vec3 projected_point;
    t_lst object;
    float epsilon = 0.001;  // Adjust this value depending on the desired precision.

    object.content = cylinder;
    projection = scalar_prod(vec_sub(hit_point, cylinder->orig), cylinder->axis);

    if (fabs(get_cylinder_distance_t(&object, ray) - get_cylinder_distance_t_proj(&object, ray)) < epsilon)
    {
        projected_point = vec_add(cylinder->orig, vec_mult(cylinder->axis, projection));
        normal_hit_point = vec_sub(hit_point, projected_point);
    }
    else if (fabs(get_cylinder_distance_t(&object, ray) - find_top_cap_intersection(&object, ray)) < epsilon)
    {
        normal_hit_point = cylinder->axis;
    }
    else if (fabs(get_cylinder_distance_t(&object, ray) - find_bottom_cap_intersection(cylinder, ray)) < epsilon)
    {
        normal_hit_point = vec_mult(cylinder->axis, -1.0f);
    }

    unit_normal_hit_point = unit_vec3(normal_hit_point);
    unit_light = unit_vec3(scene->light->orig);
    angle = scalar_prod(unit_normal_hit_point, unit_light);
    angle = fmax(angle, 0.0f);
    return (angle);
}

t_vec3 get_normal_cylinder(t_vec3 hit_point, t_cylinder *cylinder, t_scene *scene, t_ray ray)
{
	t_vec3 normal_hit_point;
	t_vec3 unit_normal_hit_point;
	float_t projection;
	t_vec3 projected_point;
	t_lst object;
	float epsilon = 0.001;  // Adjust this value depending on the desired precision.

	object.content = cylinder;
	projection = scalar_prod(vec_sub(hit_point, cylinder->orig), cylinder->axis);

	if (fabs(get_cylinder_distance_t(&object, ray) - get_cylinder_distance_t_proj(&object, ray)) < epsilon)
	{
		projected_point = vec_add(cylinder->orig, vec_mult(cylinder->axis, projection));
		normal_hit_point = vec_sub(hit_point, projected_point);
	}
	else if (fabs(get_cylinder_distance_t(&object, ray) - find_top_cap_intersection(&object, ray)) < epsilon)
	{
		normal_hit_point = cylinder->axis;
	}
	else if (fabs(get_cylinder_distance_t(&object, ray) - find_bottom_cap_intersection(cylinder, ray)) < epsilon)
	{
		normal_hit_point = vec_mult(cylinder->axis, -1.0f);
	}
	unit_normal_hit_point = unit_vec3(normal_hit_point);
	return (unit_normal_hit_point);
}

int calc_distant_t(t_hit_calc *calc)
{
	float_t t1;
	float_t t2;
	float_t smallest_t;

	t1 = (-calc->b - sqrt(calc->discriminant)) / (2.0f * calc->a);
	t2 = (-calc->b + sqrt(calc->discriminant)) / (2.0f * calc->a);
	smallest_t = fmin(t1, t2);
	calc->distance_t = smallest_t;
	if (calc->distance_t < 0)
		return (-1);
	return (0);
}


