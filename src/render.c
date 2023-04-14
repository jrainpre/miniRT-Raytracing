#include "miniRT.h"

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	t_img	*img;

	img = data->img;
	if (x < 0 || x >= data->win.width || y < 0 || y >= data->win.height)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = color;
}

float_t	deg_to_rad(float_t deg)
{
	return (deg * (M_PI / 180.0));
}

t_vec3 get_reflect_ray(t_vec3 vector, t_vec3 normal)
{
	t_vec3 reflection;

	reflection = vec_sub(vector, vec_mult(normal, 2 * scalar_prod(vector, normal)));
	return (reflection);
}

t_vec3 get_normal_to_surface(t_lst *object, t_vec3 hit_point)
{
	t_vec3 normal;
	t_sphere *sphere;
	t_plane *plane;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->content;
		normal = vec_sub(hit_point, sphere->orig);
		normal = unit_vec3(normal);
	}
	else if (object->type == PLANE)
	{
		plane = (t_plane *)object->content;
		normal = plane->normal_vec;
		normal = unit_vec3(normal);

	}
	// else if (object->type == CYLINDER)

	else
		normal = (t_vec3){0, 0, 0};
	return (normal);
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double		random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

t_vec3	vector(double x, double y, double z)
{
	return ((t_vec3){x, y, z});
}
double		random_from(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_vector_in(double min, double max)
{
	return (vector(random_from(min, max),
							random_from(min, max),
							random_from(min, max)));
}

double		length_squared(t_vec3 vector)
{
	double x;
	double y;
	double z;

	x = vector.x * vector.x;
	y = vector.y * vector.y;
	z = vector.z * vector.z;
	return (x + y + z);
}

t_vec3		random_in_unit_sphere(void)
{
	t_vec3 random;

	while (1)
	{
		random = random_vector_in(-1.0, 1.0);
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}

t_vec3	random_vector(void)
{
	return (vector(random_double(), random_double(), random_double()));
}






double		canonical_random(void)
{
	return (random_from(0.0, 1.0));
}




t_vec3		random_unit_vector(void)
{
	t_vec3 normalized_in_sphere;

	normalized_in_sphere = unit_vec3(random_in_unit_sphere());
	return (normalized_in_sphere);
}




t_vec3		random_in_hemisphere(const t_vec3 normal)
{
	t_vec3 in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (scalar_prod(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	return (vec_mult(in_unit_sphere, -1));
}

static t_vec3	calulate_fuzzed_reflected(t_vec3 direction,
												t_vec3 normal,
												double fuzziness)
{
	const t_vec3	incident = unit_vec3(direction);
	const t_vec3	reflected = get_reflect_ray(incident, normal);
	const t_vec3	fuzz = vec_mult(random_in_unit_sphere(), fuzziness);
	const t_vec3	fuzzed_reflected = vec_add(reflected, fuzz);

	return (fuzzed_reflected);
}


float_t get_reflect_factor(t_lst *object)
{
        if (object->type == SPHERE)
                return (((t_sphere *)object->content)->reflect_factor);
        // else if (object->type == PLANE)
        //         return (((t_plane *)object->content)->reflect_factor);
        // else if (object->type == CYLINDER)
        //         return (((t_cylinder *)object->content)->reflect_factor);

        else
              return (0);
}

t_color follow_ray(t_scene *scene, t_ray ray)
{
	float_t distance_t;
	t_vec3 hit_point;
	t_vec3 normal;
	t_lst *object;
	t_color color;
	float_t factor = 1.0f;
	int i = 0;
	// t_color  skycolor = (t_color){0.6, 0.7, 0.9, 1};
	t_color act_color;
	act_color = (t_color){0, 0, 0, 1};

	while (i < 5)
	{
		object = get_closest_hit(scene, ray);
		if (object == NULL)
			return (act_color);
		distance_t = get_distance_t(object, ray);
		hit_point = vec_add(ray.orig, vec_mult(ray.dir, distance_t));
		normal = get_normal_to_surface(object, hit_point);
		color = light_shade_object(scene, object, ray);
		act_color = color_add(color_mult(color, factor), act_color);
		factor *= 0.7 * get_reflect_factor(object);
		ray.orig = vec_add(ray.orig, vec_mult(normal, 0.0001));
		ray.dir = calulate_fuzzed_reflected(ray.dir, normal, 1 - get_reflect_factor(object));
		 i++;
	}
	// act_color = color_clamp(act_color, 0.0f, 1.0f);
	return(act_color);
}

t_color color_div(t_color color, float_t div)
{
	t_color new_color;

	new_color.r = color.r / div;
	new_color.g = color.g / div;
	new_color.b = color.b / div;
	new_color.a = color.a;
	return (new_color);
}

void	render_scene(t_data *data)
{
	t_camera	*cam;
	t_ray		ray;
	int			i;
	int			j;
	float_t		u;
	float_t		v;
	t_lst		*runner;
	// t_lst *object;
	int color;
	t_color act_color;
	t_color final_color = {0, 0, 0, 1};

	cam = data->scene->cam;
	runner = data->scene->objects->head;
	j = 0;
	while (j < data->win.height)
	{
		i = 0;
		while (i < data->win.width)
		{
			u = (float_t)i / (data->win.width - 1);
			v = (float_t)j / (data->win.height - 1);
			ray.orig = cam->orig;
			ray.dir = vec_sub(vec_add(vec_add(vec_mult(cam->horizontal, u), vec_mult(cam->vertical, v)), cam->upper_left_corner), cam->orig);
				const t_vec3	fuzz = vec_mult(random_in_unit_sphere(), 0.0000001);
			ray.dir = vec_add(ray.dir, fuzz);
			act_color = follow_ray(data->scene, ray);
			data->pixelcolors[i * data->win.width + j] = color_add(data->pixelcolors[i * data->win.width + j], act_color);
			final_color = color_div(data->pixelcolors[i * data->win.width + j], data->pixelcolors_int);
			final_color = color_clamp(final_color, 0.0f, 1.0f);
			color = color_conversion(final_color);
			img_pix_put(data, i, j, color);
			i++;
		}
		j++;
	}
	data->pixelcolors_int++;

}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->win.height)
	{
		i = 0;
		while (i < data->win.width)
		{
			img_pix_put(data, i, j, color);
			i++;
		}
		j++;
	}
}
