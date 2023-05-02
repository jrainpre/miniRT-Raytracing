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

void get_normal_to_surface(t_lst *object, t_hit_info *hit_info)
{
	t_vec3 normal;
	t_sphere *sphere;
	t_plane *plane;

	if (object->type == SPHERE)
	{
		sphere = (t_sphere *)object->content;
		normal = vec_sub(hit_info->hitpoint, sphere->orig);
		hit_info->normal = unit_vec3(normal);
	}
	else if (object->type == PLANE)
	{
		plane = (t_plane *)object->content;
		normal = plane->normal_vec;
		hit_info->normal = unit_vec3(normal);
	}
	else if (object->type == CYLINDER)
		get_normal_cylinder(hit_info, (t_cylinder *)object->content);
	else
		hit_info->normal = (t_vec3){0, 0, 0};
}

float_t		random_float(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

t_vec3	vector(float_t x, float_t y, float_t z)
{
	return ((t_vec3){x, y, z});
}
float_t		random_from(float_t min, float_t max)
{
	return (min + (max - min) * random_float());
}

t_vec3	random_vector_in(float_t min, float_t max)
{
	return (vector(random_from(min, max),
							random_from(min, max),
							random_from(min, max)));
}

t_vec3		random_in_unit_sphere(void)
{
	t_vec3 random;

	while (1)
	{
		random = random_vector_in(-1.0, 1.0);
		if (scalar_prod(random, random) >= 1)
			continue ;
		return (random);
	}
}

t_vec3	random_vector(void)
{
	return (vector(random_float(), random_float(), random_float()));
}

static t_vec3	calulate_fuzzed_reflected(t_vec3 direction, t_vec3 normal, double fuzziness)
{
	t_vec3 reflected;
	t_vec3 fuzz;
	t_vec3 fuzzed_reflected;

	reflected = get_reflect_ray(unit_vec3(direction), normal);
	fuzz = vec_mult(random_in_unit_sphere(), fuzziness);
	fuzzed_reflected = vec_add(reflected, fuzz);

	return (fuzzed_reflected);
}


float_t get_reflect_factor(t_lst *object)
{
        if (object->type == SPHERE)
                return (((t_sphere *)object->content)->reflect_factor);
        else if (object->type == PLANE)
                return (((t_plane *)object->content)->reflect_factor);
        else if (object->type == CYLINDER)
                return (((t_cylinder *)object->content)->reflect_factor);
        else
              return (0);
}

t_color follow_ray(t_scene *scene, t_ray ray)
{
	t_hit_info hit_info;
	float_t distance_t;
	t_vec3 hit_point;
	t_color color;
	float_t factor = 1.0f;
	int i = 0;
	t_color act_color = (t_color){0, 0, 0, 1};

	while (i < 1)
	{
		get_closest_hit(scene, ray, &hit_info);
		if (hit_info.object == NULL)
			return (act_color);
		hit_info.hitpoint = vec_add(ray.orig, vec_mult(ray.dir, hit_info.distance));
		get_normal_to_surface(hit_info.object, &hit_info);
		color = light_shade_object(scene, hit_info.object, &hit_info);
		act_color = color_add(color_mult(color, factor), act_color);
		if (hit_info.object->is_slected)
			factor = 0.0f;
		else
			factor *= 0.7 * get_reflect_factor(hit_info.object);
		ray.orig = vec_add(ray.orig, vec_mult(hit_info.normal, VEC_OFFSET));
		ray.dir = calulate_fuzzed_reflected(ray.dir, hit_info.normal, 1 - get_reflect_factor(hit_info.object));
		 i++;
	}
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
	t_color act_color;
	t_color final_color;

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
				const t_vec3	fuzz = vec_mult(random_in_unit_sphere(), FUZZ_FACTOR);
			ray.dir = vec_add(ray.dir, fuzz);
			act_color = follow_ray(data->scene, ray);
			data->pixelcolors[j * data->win.width + i] = color_add(data->pixelcolors[j * data->win.width + i], act_color);
			final_color = color_div(data->pixelcolors[j * data->win.width + i], data->pixelcolors_int);
			final_color = color_clamp(final_color, 0.0f, 1.0f);
			img_pix_put(data, i, j, color_conversion(final_color));
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
