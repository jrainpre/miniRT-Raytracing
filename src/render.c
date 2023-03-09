#include "miniRT.h"

void	img_pix_put(t_img *img, t_pt pt)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = pt.color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			img_pix_put(img, (t_pt){j, i, 0, color});
			j++;
		}
		i++;
	}
}

float_t	deg_to_rad(float_t deg)
{
	return (deg * (M_PI / 180.0));
}

int	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vec	orig_diff;
	float_t	a;
	float_t	b;
	float_t	c;
	float_t	discriminant;

	orig_diff = vec_sub(ray.orig, sphere.orig);
	a = scalar_prod(ray.dir, ray.dir);
	b = 2.0 * scalar_prod(orig_diff, ray.dir);
	c = scalar_prod(orig_diff, orig_diff) - sphere.radius * sphere.radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

void	render_scene(t_data *data)
{
	t_camera	cam;
	t_ray		ray;
	t_sphere	sphere;
	int			i;
	int			j;
	float_t		u;
	float_t		v;

	cam.orig = (t_pt){0, 0, 10, NOCOLOR};
	cam.orientation = (t_vec){0, 0, -1, NOCOLOR};
	cam.fov = 70;
	cam.sensor_height = 2;
	cam.sensor_width = (WIN_W / WIN_H) * cam.sensor_height;
	cam.focal_length = (cam.sensor_width / 2) / tanf(deg_to_rad(cam.fov / 2.0));
	cam.vertical = (t_vec){0, cam.sensor_height, 0, NOCOLOR};
	cam.horizontal = (t_vec){cam.sensor_width, 0, 0, NOCOLOR};
	cam.lower_left_corner = vec_sub(cam.orig, vec_add(vec_add(vec_div(cam.horizontal, 2), vec_div(cam.vertical, 2)), (t_vec){0, 0, cam.focal_length, NOCOLOR}));

	sphere.orig = (t_pt){0, 0, -100, NOCOLOR};
	sphere.radius = 40.0;
	sphere.color = (t_color){0, 255, 0};

	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			u = i / (WIN_W - 1);
			v = j / (WIN_H - 1);
			ray.orig = cam.orig;
			ray.dir = vec_sub(vec_add(vec_add(vec_mult(cam.horizontal, u), vec_mult(cam.vertical, v)), cam.lower_left_corner), cam.orig);
			if (hit_sphere(sphere, ray))
				img_pix_put(&data->img, (t_pt){i, j, 0, GREEN});
			i++;
		}
		j++;
	}
}
