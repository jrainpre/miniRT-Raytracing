#ifndef MINIRT_H
# define MINIRT_H

/* C System Headers */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* 42 Library Headers */
# include "libft.h"
# include "mlx.h"

/* Project Headers */
# include "ambient_light.h"
# include "camera.h"
# include "colors.h"
# include "cylinder.h"
# include "function_tests.h"
# include "image.h"
# include "light.h"
# include "linked_list.h"
# include "matrix.h"
# include "plane.h"
# include "ray.h"
# include "scene.h"
# include "sphere.h"
# include "vector.h"

/* Macros */

/* Global Variables */

/* Structs */
typedef struct s_resolution
{
	int	x;
	int	y;
}			t_resolution;
typedef struct s_scene
{
	t_resolution	res;
	t_camera		*cam;
	t_light			*light;
	t_ambient_light	*ambient_light;
	t_lst_ref		*objects;
}			t_scene;

/* Functions */

t_vec3	mat_mult(t_mat3x3 mat, t_vec3 pt);
t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_mult(t_vec3 vec, float_t factor);
t_vec3	vec_div(t_vec3 vec, float_t factor);
float_t	scalar_prod(t_vec3 vec1, t_vec3 vec2);
t_vec3	cross_prod(t_vec3 vec1, t_vec3 vec2);
float_t	vec_length(t_vec3 vec);
t_vec3	unit_vec3(t_vec3 vec);
int		vec_cmp(t_vec3 vec1, t_vec3 vec2);
t_pt3	ray_point_at(t_ray ray, float_t t);

void			*free_scene_null(t_scene *scene);
t_scene			*init_scene(void);
t_camera		*init_camera(t_camera *cam);
t_light			*init_light(t_light *light);
t_ambient_light	*init_ambient_light(t_ambient_light *ambient_light);
int				fill_dummy_scene(t_scene *scene);
int				add_sphere(t_lst_ref *objects, t_pt3 orig, float_t r, t_color col);

t_data	*init_data(void);
void	*free_data_null(t_data *data);
void	*malloc_or_print_error(size_t size);
void	*free_null(void *ptr);

#endif
