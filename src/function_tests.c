#include "miniRT.h"

void	vector_test(void)
{
	t_vec3	vec1;
	t_vec3	vec2;
	t_vec3	res;
	float_t	factor;
	float_t	scalar_res;
	float_t	length;

	vec1 = (t_vec3){1, 2, 0};
	vec2 = (t_vec3){0, 3, 1};
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

	res = unit_vec3(vec1);
	printf("unit vector of vec1\n");
	printf("x: %19.15f\n", res.x);
	printf("y: %19.15f\n", res.y);
	printf("z: %19.15f\n", res.z);
	printf("\n");
}

void	ray_test(void)
{
	t_ray	ray;
	t_vec3	dir;
	t_pt3	res;
	float_t	t;

	dir = (t_vec3){1, 0, 0};
	ray.orig = (t_pt3){100, 0, 0};
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

void	print_vec3(char *title, t_vec3 vec)
{
	printf("%s\n", title);
	printf("x: %10.4f\n", vec.x);
	printf("y: %10.4f\n", vec.y);
	printf("z: %10.4f\n", vec.z);
	printf("\n");
}

void	print_color(char *title, t_color color)
{
	printf("%s\n", title);
	printf("x: %10.4f\n", color.r);
	printf("y: %10.4f\n", color.g);
	printf("z: %10.4f\n", color.b);
	printf("a: %10.4f\n", color.a);
	printf("\n");
}

void	print_object(void *object, t_object_type type)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_camera	*cam;

	if (type == SPHERE)
	{
		sphere = (t_sphere *)object;
		print_vec3("sphere->orig", sphere->orig);
		printf("sphere->radius\nr: %10.4f\n\n", sphere->radius);
		print_color("sphere->color", sphere->color);
	}
	else if (type == CYLINDER)
	{
		cylinder = (t_cylinder *)object;
		print_vec3("cylinder->orig", cylinder->orig);
		print_vec3("cylinder->axis", cylinder->axis);
		printf("cylinder->radius\nr: %10.4f\n\n", cylinder->radius);
		printf("cylinder->height\nr: %10.4f\n\n", cylinder->height);
		print_color("cylinder->color", cylinder->color);
	}
	else if (type == PLANE)
	{
		plane = (t_plane *)object;
		print_vec3("plane->point", plane->point);
		print_vec3("plane->normal_vec", plane->normal_vec);
		print_color("plane->color", plane->color);
	}
	else if (type == CAMERA)
	{
		cam = (t_camera *)object;
		print_vec3("cam->orig", cam->orig);
		print_vec3("cam->orientation", cam->orientation);
		print_vec3("cam->left", cam->left);
		print_vec3("cam->up", cam->up);
		printf("cam->fov\nr: %10.4f\n\n", cam->fov);
		printf("cam->sensor_height\nr: %10.4f\n\n", cam->sensor_height);
		printf("cam->sensor_width\nr: %10.4f\n\n", cam->sensor_width);
		printf("cam->focal_length\nr: %10.4f\n\n", cam->focal_length);
		print_vec3("cam->vertical", cam->vertical);
		print_vec3("cam->horizontal", cam->horizontal);
		print_vec3("cam->upper_left_corner", cam->upper_left_corner);
	}
}

void	test_mat_dot_prod(void)
{
	t_mat3x3	a;
	t_mat3x3	b;
	t_mat3x3	c;
	t_mat3x3	d;

	a = (t_mat3x3){
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};
	b = (t_mat3x3){
		1, 4, 7,
		2, 5, 8,
		3, 6, 9
	};
	c = (t_mat3x3){
		-9, -6, -3,
		-8, -5, -2,
		-7, -4, -1
	};
	d = mat3x3_dot_prod(b, c);
	printf("d = b * c\n");
	printf("%10.4f %10.4f %10.4f\n", d.c1r1, d.c2r1, d.c3r1);
	printf("%10.4f %10.4f %10.4f\n", d.c1r2, d.c2r2, d.c3r2);
	printf("%10.4f %10.4f %10.4f\n", d.c1r3, d.c2r3, d.c3r3);
	printf("\n");
}

void	test_valid_ambient_lights(void)
{
	char	*s1 = "A 0.2 255,255,255\n";
	char	*s2 = "A 0.2 255,255,255\n";
	char	*s3 = "A    0.2 255,255,255";
	char	*s4 = "As    0.2 255,255,255\n";
	char	*s5 = "A    -0.2 255,255,255\n";
	char	*s6 = "A    -0.2 ,255,255\n";
	char	*s7 = "A    -0.2 , 255,255\n";
	char	*s8 = "    A    0.2 5,255,255\n";

	printf("\"%s\"\n%d\n\n", s1, is_valid_ambient_light(s1));
	printf("\"%s\"\n%d\n\n", s2, is_valid_ambient_light(s2));
	printf("\"%s\"\n%d\n\n", s3, is_valid_ambient_light(s3));
	printf("\"%s\"\n%d\n\n", s4, is_valid_ambient_light(s4));
	printf("\"%s\"\n%d\n\n", s5, is_valid_ambient_light(s5));
	printf("\"%s\"\n%d\n\n", s6, is_valid_ambient_light(s6));
	printf("\"%s\"\n%d\n\n", s7, is_valid_ambient_light(s7));
	printf("\"%s\"\n%d\n\n", s8, is_valid_ambient_light(s8));
}
