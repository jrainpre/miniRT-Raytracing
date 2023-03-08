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
# include "image.h"
# include "light.h"
# include "linked_list.h"
# include "matrix.h"
# include "plane.h"
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
	t_resolution res;
	t_camera	*cam;
	t_lst_ref	*lights;
	t_lst_ref	*ambient_lights;
	t_lst_ref	*spheres;
	t_lst_ref	*planes;
	t_lst_ref	*cylinders;

}			t_scene;

/* Functions */

t_pt	mat_mult(t_mat3x3 mat, t_pt pt);
t_pt	vec_add(t_pt pt1, t_pt pt2);
t_pt	vec_sub(t_pt pt1, t_pt pt2);

void free_scene(t_scene *scene);
void init_scene(t_scene *scene);
void fill_dummy_scene(t_scene *scene);

#endif
