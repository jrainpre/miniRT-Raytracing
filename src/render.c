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

int	hit_sphere(t_sphere *sphere, t_ray ray)
{
	t_vec3	orig_diff;
	float_t	a;
	float_t	b;
	float_t	c;
	float_t	discriminant;

	orig_diff = vec_sub(ray.orig, sphere->orig);
	a = scalar_prod(ray.dir, ray.dir);
	b = 2.0 * scalar_prod(orig_diff, ray.dir);
	c = scalar_prod(orig_diff, orig_diff) - sphere->radius * sphere->radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
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
				ray.dir = vec_sub(vec_add(vec_add(vec_mult(cam->horizontal, u), vec_mult(cam->vertical, v)), cam->lower_left_corner), cam->orig);
				if (runner->type == SPHERE)
					if (hit_sphere(runner->content, ray))
						img_pix_put(data, i, j, GREEN);
				i++;
			}
			j++;
		}
		runner = runner->next;
	}
}
