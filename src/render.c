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

int follow_ray(t_scene *scene, t_ray ray)
{
	float_t distance_t;
	t_vec3 hit_point;
	t_vec3 normal;
	t_lst *object;
	t_color color;
	float_t factor = 1.0f;
	int i = 0;
	color = (t_color){0, 0, 0, 0};
	t_color act_color;
	act_color = (t_color){0, 0, 0, 0};

	while (i < 100)
	{
		object = get_closest_hit(scene, ray);
		if (object == NULL)
			return (color_conversion(color));
		distance_t = get_distance_t(object, ray);
		hit_point = vec_add(ray.orig, vec_mult(ray.dir, distance_t));
		normal = get_normal_to_surface(object, hit_point);
		color = light_shade_object(scene, object, ray);
		color = color_mult(color, factor);
		act_color = color_add(act_color, color);
		factor *= 0.7f;
		ray.orig = vec_add(ray.orig, vec_mult(normal, 0.000001));
		ray.dir = get_reflect_ray(ray.dir, normal);
		i++;
	}
	return(color_conversion(color));



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
			color = follow_ray(data->scene, ray);
			img_pix_put(data, i, j, color);
			i++;
		}
		j++;
	}
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
