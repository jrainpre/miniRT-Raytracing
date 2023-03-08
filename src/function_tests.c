#include "miniRT.h"

void	vector_test(void)
{
	t_vec	vec1;
	t_vec	vec2;
	t_vec	res;
	float_t	factor;
	float_t	scalar_res;
	float_t	length;

	vec1 = (t_vec){1, 2, 0, NOCOLOR};
	vec2 = (t_vec){0, 3, 1, NOCOLOR};
	factor = 2;
	printf("vec1\n");
	printf("x: %19.15f\n", vec1.x);
	printf("y: %19.15f\n", vec1.y);
	printf("z: %19.15f\n", vec1.z);
	printf("\n");

	printf("vec2\n");
	printf("x: %19.15f\n", vec2.x);
	printf("y: %19.15f\n", vec2.y);
	printf("z: %19.15f\n", vec2.z);
	printf("\n");

	printf("factor: %19.15f\n", factor);
	printf("\n");

	res = vec_add(vec1, vec2);
	printf("vec1 + vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_sub(vec1, vec2);
	printf("vec1 - vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_mult(vec1, factor);
	printf("vec1 * factor\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	res = vec_div(vec1, factor);
	printf("vec1 / factor\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	scalar_res = scalar_prod(vec1, vec2);
	printf("vec1 * vec2\n");
	printf("scalar_res: %19.15f\n", scalar_res);
	printf("\n");

	res = cross_prod(vec1, vec2);
	printf("vec1 x vec2\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");

	length = vec_length(vec1);
	printf("|vec1|\n");
	printf("length: %19.15f\n", length);
	printf("\n");

	res = unit_vec(vec1);
	printf("unit vector of vec1\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}

void	ray_test(void)
{
	t_ray	ray;
	t_vec	dir;
	t_pt	res;
	float_t	t;

	dir = (t_vec){1, 0, 0, NOCOLOR};
	ray.orig = (t_pt){100, 0, 0, NOCOLOR};
	ray.dir = dir;
	t = -100;

	printf("ray.orig\n");
	printf("x: %19.15f\n", ray.orig.x);
	printf("y: %19.15f\n", ray.orig.y);
	printf("z: %19.15f\n", ray.orig.z);
	printf("\n");

	printf("ray.dir\n");
	printf("x: %19.15f\n", ray.dir.x);
	printf("y: %19.15f\n", ray.dir.y);
	printf("z: %19.15f\n", ray.dir.z);
	printf("\n");

	printf("t: %19.15f\n", t);
	printf("\n");

	res = ray_point_at(ray, t);
	printf("P(t) = ray.orig + t * ray.dir\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}

float_t	deg_to_rad(float_t deg)
{
	return (deg * (M_PI / 180.0));
}

int	hit_sphere(t_sphere sphere, t_ray ray)
{
	float_t	discriminant;
	float_t	p;
	float_t	q;
	t_vec	orig_diff;

	orig_diff = vec_sub(ray.orig, sphere.orig);
	p = 2 * powf(scalar_prod(ray.dir, orig_diff) / scalar_prod(ray.dir, ray.dir), 2);
	q = scalar_prod(orig_diff, orig_diff) - powf(sphere.radius, 2);
	discriminant = p - q;
	return (discriminant > 0);
}

void	background_test(t_img *img)
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
	cam.fov = 130;
	cam.sensor_height = 2;
	cam.sensor_width = (WIN_W / WIN_H) * cam.sensor_height;
	cam.focal_length = cam.sensor_width / 2 * atanf(deg_to_rad(180 / 2.0));
	cam.vertical = (t_vec){0, cam.sensor_height, 0, NOCOLOR};
	cam.horizontal = (t_vec){cam.sensor_width, 0, 0, NOCOLOR};
	cam.lower_left_corner = vec_sub(cam.orig, vec_add(vec_add(vec_div(cam.horizontal, 2), vec_div(cam.vertical, 2)), (t_vec){0, 0, cam.focal_length, NOCOLOR}));

	sphere.orig = (t_pt){0, 0, -50, NOCOLOR};
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
			//printf("hit_sphere: %d\n", hit_sphere(sphere, ray));
			if (hit_sphere(sphere, ray))
				img_pix_put(img, (t_pt){i, j, 0, GREEN});
			// printf("x: %19.15f\n", ray.dir.x);
			// printf("y: %19.15f\n", ray.dir.y);
			// printf("z: %19.15f\n", ray.dir.z);
			// printf("\n");
			i++;
		}
		j++;
	}
}
