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
# include <float.h>

/* 42 Library Headers */
# include "libft.h"
# include "mlx.h"

/* Project Headers */
# include "ambient_light.h"
# include "camera.h"
# include "colors.h"
# include "cylinder.h"
# include "deterministic_finite_automaton.h"
# include "light.h"
# include "linked_list.h"
# include "matrix.h"
# include "plane.h"
# include "ray.h"
# include "scene.h"
# include "sphere.h"
# include "image.h"
# include "vector.h"
# include "function_tests.h"

/* Macros */

/* Global Variables */

/* Structs */
typedef struct s_scene
{
	t_camera		*cam;
	t_light			*light;
	t_ambient_light	*ambient_light;
	t_lst_ref		*objects;
}			t_scene;

/* Functions */

t_vec3			mat_mult(t_mat3x3 mat, t_vec3 vec);
t_mat3x3		mat3x3_dot_prod(t_mat3x3 a, t_mat3x3 b);
t_vec3			vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec_mult(t_vec3 vec, float_t factor);
t_vec3			vec_div(t_vec3 vec, float_t factor);
float_t			scalar_prod(t_vec3 vec1, t_vec3 vec2);
t_vec3			cross_prod(t_vec3 vec1, t_vec3 vec2);
float_t			vec_length(t_vec3 vec);
t_vec3			unit_vec3(t_vec3 vec);
int				vec_cmp(t_vec3 vec1, t_vec3 vec2);
t_pt3			ray_point_at(t_ray ray, float_t t);
float_t 		clamp(float_t value, float_t min, float_t max);
t_vec3			rotate_x(t_vec3 vec, float_t angle);
t_vec3			rotate_y(t_vec3 vec, float_t angle);
t_mat3x3		get_rot_x(float_t angle);
float_t 		vec3_distance(t_vec3 vec1, t_vec3 vec2);

void			*free_scene_null(t_scene *scene);
t_scene			*init_scene(void);
t_camera		*init_camera(t_resolution res, char *line);
t_vec3			calc_upper_left_corner(t_camera *cam);
void			translate_camera(t_camera *cam, t_vec3 vec);
void			rotate_y_camera(t_camera *cam, float_t angle);
void			rotate_x_camera(t_camera *cam, float_t angle);
void			rotate_camera_around_left_axis(t_camera *cam, float_t angle);
void			tilt_down(t_camera *cam, float_t angle);
void			tilt_up(t_camera *cam, float_t angle);
void			dolly_in(t_camera *cam, float_t meters);
void			dolly_out(t_camera *cam, float_t meters);
void			truck_left(t_camera *cam, float_t meters);
void			truck_right(t_camera *cam, float_t meters);
void			pedestal_up(t_camera *cam, float_t meters);
void			pedestal_down(t_camera *cam, float_t meters);
void			pan_left(t_camera *cam, float_t angle);
void			pan_right(t_camera *cam, float_t angle);
t_light			*init_light(char *line);
void			translate_light(t_light *light, t_vec3 vec);
t_ambient_light	*init_ambient_light(char *line);
int				fill_scene(t_scene *scene, t_lst_ref *scene_lines, t_resolution win);
int				add_sphere(t_lst_ref *objects, char *line);
int				add_plane(t_lst_ref *objects, char *line);
int				add_cylinder(t_lst_ref *objects, char *line);
t_color			get_color_from_str_arr(char **str);
t_vec3			get_vec_from_str_arr(char **str);

t_data			*init_data(void);
void			*free_data_null(t_data *data);
void			*malloc_or_print_error(size_t size);
void			*free_null(void *ptr);
void			*free_arr_null(char **arr);
double			ft_atof(const char *str);
t_lst_ref		*read_file(char *file);
int				arguments_valid(int argc, char **argv);
int				is_valid_ratio(float_t ratio);
int				is_valid_color(t_color color);
int				is_normalized(t_vec3 vec);


int calc_distant_t(t_hit_calc *calc);
float_t get_light_angle(t_vec3 hit_point, t_sphere *sphere, t_scene *scene);
float_t get_light_angle_plane(t_vec3 hit_point, t_plane *plane, t_scene *scene);
t_lst	*get_closest_hit(t_scene *scene, t_ray ray);
float_t	get_distance_t(t_lst *object, t_ray ray);
float_t get_sphere_distance_t(t_lst *object, t_ray ray);
float_t get_plane_distance_t(t_lst *object, t_ray ray);
t_color light_shade_object(t_scene *scene, t_lst *object, t_ray ray);
t_vec3 get_hitpoint_object(t_lst *object, float_t distance_t, t_ray ray);
t_vec3 get_hitpoint_sphere(t_lst *object, float_t distance_t, t_ray ray);
t_vec3 get_hitpoint_plane(t_lst *object, float_t distance_t, t_ray ray);
t_color get_color_hitpoint(t_scene *scene, t_lst *object, t_ray ray, t_vec3 hitpoint);
t_color get_ambient_color_object(t_scene *scene, t_lst *object);
t_color get_ambient_color_sphere(t_scene *scene, t_lst *object);
t_color	get_ambient_color_plane(t_scene *scene, t_lst *object);
t_color get_diffuse_color_object(t_scene *scene, t_lst *object, t_vec3 hitpoint);
t_color get_diffuse_color_sphere(t_scene *scene, t_lst *object, t_vec3 hitpoint);
t_color	get_diffuse_light_plane(t_scene *scene, t_lst *object, t_vec3 hitpoint);
t_color get_specular_color_object(t_scene *scene, t_lst *object, t_vec3 hitpoint);
t_vec3 get_reflection_vec_sphere(t_vec3 hit_point, t_sphere *sphere, t_scene *scene);
t_color get_specular_color_sphere(t_scene *scene, t_lst *object, t_vec3 hitpoint);




int				hit_plane(t_plane *plane, t_ray ray, t_scene *scene);

#endif
