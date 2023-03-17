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

void	render_scene(t_data *data)
{
	t_camera	*cam;
	t_ray		ray;
	int			i;
	int			j;
	float_t		u;
	float_t		v;
	t_lst		*runner;
	t_lst *object;
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
			object = get_closest_hit(data->scene, ray);
			if (object == NULL)
			{
				i++;
				continue;
			}
			color = light_shade_object(data->scene, object, ray);
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
