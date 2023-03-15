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

t_vec3 get_reflection_vec(t_vec3 hit_point, t_sphere *sphere, t_scene *scene)
{
	t_vec3 unit_normal_hit_point;
	t_vec3 b;
	t_vec3 reflection;
	t_vec3 to_light;

	//R = 2*n*dot_product(n,L) - L   // When L goes from the vertex to the light source
	to_light = vec_sub(scene->light->orig, hit_point);
	to_light = unit_vec3(to_light);
	unit_normal_hit_point = unit_vec3(vec_sub(hit_point, sphere->orig));
	b = vec_mult(unit_normal_hit_point, 2 * scalar_prod(unit_normal_hit_point, to_light));
	reflection = vec_sub(b, to_light);
	return (reflection);
}

t_color get_spectecular_color(t_scene *scene, t_sphere *sphere, t_color act_color, t_vec3 hit_point)
{
	t_vec3 reflection;
	t_vec3 to_camera;
	t_vec3 to_light;
	float_t angle;

	reflection = unit_vec3(get_reflection_vec(hit_point, sphere, scene));
	to_camera = unit_vec3(vec_sub(scene->cam->orig, hit_point));
	to_light = unit_vec3(vec_sub(scene->light->orig, hit_point));
	angle = scalar_prod(to_camera, reflection);
	angle = clamp(angle, 0.0f, 1.0f);
	angle = pow(angle, 40);
	act_color = color_mult_color(sphere->color, scene->light->color);
	act_color = color_mult(act_color, scene->light->ratio);
	act_color = color_mult(act_color, angle);
	act_color = color_clamp(act_color, 0.0f, 1.0f);
	return (act_color);
}


t_color get_diffuse_color(t_scene *scene, t_sphere *sphere, t_color act_color, t_vec3 hit_point)
{
	float_t angle;

	angle = get_light_angle(hit_point, sphere, scene);
	act_color = color_mult(act_color, angle * scene->light->ratio);
	act_color = color_clamp(act_color, 0.0f, 1.0f);
	return (act_color);
}

t_color get_ambient_color(t_scene *scene, t_sphere *sphere, t_color act_color)
{
	t_color ambient;

	ambient = color_mult_color(sphere->color, scene->ambient_light->color);
	ambient = color_mult(ambient, scene->ambient_light->ratio);
	act_color = color_clamp(ambient, 0.0f, 1.0f);
	return (act_color);
}

int get_color_sphere(t_sphere *sphere, t_scene *scene, t_vec3 hit_point)
{
	t_color ambient;
	t_color diffuse;
	t_color specular;
	t_color result;

	ambient = get_ambient_color(scene, sphere, sphere->color);
	diffuse = get_diffuse_color(scene, sphere, sphere->color, hit_point);
	specular = get_spectecular_color(scene, sphere, sphere->color, hit_point);
	result = color_add(ambient, diffuse);

	result = color_add(result, specular);
	result = color_clamp(result, 0.0f, 1.0f);
	return (color_conversion(result));
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
