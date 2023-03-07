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

/* Project Headers */
# include "libft.h"
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"
# include "vector.h"
# include "colors.h"
# include "matrix.h"

/* Macros */

/* Global Variables */

/* Structs */

/* Functions */

t_pt	mat_mult(t_mat3x3 mat, t_pt pt);
t_pt	vec_add(t_pt pt1, t_pt pt2);
t_pt	vec_sub(t_pt pt1, t_pt pt2);

#endif
