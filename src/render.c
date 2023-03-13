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

int light_shade_sphere(t_sphere *sphere, t_scene *scene, float_t distance_t, t_ray ray)
{
	t_vec3 hit_point;
	float_t angle;
	int color;

	hit_point = hit_point_sphere(distance_t, ray);
	color = get_color_sphere(sphere, scene, hit_point);
	(void)angle;
	return (color);
}

t_vec3 hit_point_sphere(float_t distance_t, t_ray ray)
{
	t_vec3 hit_point;
	
	hit_point = vec_add(vec_mult(ray.dir, distance_t), ray.orig);
	return (hit_point);
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

int get_color_sphere(t_sphere *sphere, t_scene *scene, t_vec3 hit_point)
{
	float_t angle;
	t_color color;
	t_color ambient;

	angle = get_light_angle(hit_point, sphere, scene);
	color = color_mult(sphere->color, angle);
	color = color_clamp(color, 0.0f, 1.0f);
	ambient = color_mix(sphere->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	color = color_add(color, ambient);
	color = color_clamp(color, 0.0f, 1.0f);
	return (color_conversion(color));
}

int calc_distant_t(t_sphere_hit_calc *calc)
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

int hit_sphere(t_sphere *sphere, t_ray ray, t_scene *scene)
{
	t_sphere_hit_calc calc;	
	t_vec3	orig_diff;

	orig_diff = vec_sub(ray.orig, sphere->orig);
	calc.a = scalar_prod(ray.dir, ray.dir);
	calc.b = 2.0 * scalar_prod(orig_diff, ray.dir);
	calc.c = scalar_prod(orig_diff, orig_diff) - sphere->radius * sphere->radius;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < 0)
		return (-1);
	if (calc_distant_t(&calc) == -1)
		return (-1);
	return (light_shade_sphere(sphere, scene, calc.distance_t, ray));

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

	cam = data->scene->cam;
	runner = data->scene->objects->head;
	while (runner)
	{
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
				if (runner->type == SPHERE)
				{
					if (hit_sphere(runner->content, ray, data->scene) != -1)
						img_pix_put(data, i, j, hit_sphere(runner->content, ray, data->scene));

				}
				i++;
			}
			j++;
		}
		runner = runner->next;
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
