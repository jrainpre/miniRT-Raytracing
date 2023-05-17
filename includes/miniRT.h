/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:24:33 by frafal            #+#    #+#             */
/*   Updated: 2023/05/17 10:14:51 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "sphere.h"
# include "image.h"
# include "vector.h"
# include "function_tests.h"
# include "random.h"

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

typedef struct s_hit_info
{
	t_vec3		hitpoint;
	t_vec3		normal;
	float_t		distance;
	t_lst		*object;
	t_ray		ray;
	int			is_inside_hit;
}			t_hit_info;

typedef struct s_it
{
	int		i;
	int		j;
	float_t	u;
	float_t	v;
}		t_it;

/* Functions */

//main.c
int				check_errors(t_data *data, int argc, char **argv);
int				init_and_fill_scene(t_data *data);
int				arguments_valid(int argc, char **argv);

float_t			find_top_cap_intersection(t_cylinder *cylinder, t_ray ray);
float_t			find_bottom_cap_intersection(t_cylinder *cylinder, t_ray ray);
float_t			get_cylinder_distance_t(t_cylinder *cylinder,
					t_ray ray, t_hit_info *hit_info);

void			get_normal_cylinder(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_proj(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_top_cap(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_bottom_cap(t_hit_info *hit_info,
					t_cylinder *cylinder);

t_color			follow_ray(t_scene *scene, t_ray ray);
t_vec3			calulate_fuzzed_reflected(t_vec3 direction,
					t_vec3 normal, double fuzz);
float_t			get_reflect_factor(t_lst *object);
void			get_normal_to_surface(t_lst *object, t_hit_info *hit_info);
t_vec3			get_reflect_ray(t_vec3 vector, t_vec3 normal);

float_t			random_float(void);
t_vec3			vector(float_t x, float_t y, float_t z);
t_vec3			random_vector_in(float_t min, float_t max);
t_vec3			random_in_unit_sphere(void);

//ambient_light_init.c
char			**split_parameters_ambient(char *line, char ***color);
t_ambient_light	*validate_and_assign_ambient(t_ambient_light *ambient,
					char **param, char **color);
t_ambient_light	*init_ambient_light(char *line);

//ambient_light.c
t_color			ambient_light_obj(t_scene *scene, t_lst *object);
t_color			ambient_light_sphere(t_scene *scene, t_sphere *sphere);
t_color			ambient_light_plane(t_scene *scene, t_plane *plane);
t_color			ambient_light_cylinder(t_scene *scene, t_cylinder *cyl);

//camera_init.c
char			**split_parameter_camera(char *line,
					char ***orig, char ***orientation);
t_camera		*validate_and_assign_camera(t_camera *cam,
					char **param, char **orig, char **orientation);
void			init_camera_properties(t_camera *cam,
					t_resolution win, char **parameters);
t_camera		*init_camera(t_resolution win, char *line);
int				is_normalized(t_vec3 vec);
t_vec3			calc_upper_left_corner(t_camera *cam);

//camera_pan.c
void			pan_left(t_camera *cam, float_t angle);
void			pan_right(t_camera *cam, float_t angle);

//camera_rotate.c
void			rotate_y_camera(t_camera *cam, float_t angle);
void			rotate_x_camera(t_camera *cam, float_t angle);
void			rotate_camera_around_left_axis(t_camera *cam, float_t angle);

//camera_tilt_dolly.c
void			tilt_down(t_camera *cam, float_t angle);
void			tilt_up(t_camera *cam, float_t angle);
void			dolly_in(t_camera *cam, float_t meters);
void			dolly_out(t_camera *cam, float_t meters);

//camera_translate_zoom.c
void			translate_camera(t_camera *cam, t_vec3 vec);
void			zoom_out(t_camera *cam, float_t focal_length);
void			zoom_in(t_camera *cam, float_t focal_length);

//camera_truck_pedestal.c
void			truck_left(t_camera *cam, float_t meters);
void			truck_right(t_camera *cam, float_t meters);
void			pedestal_up(t_camera *cam, float_t meters);
void			pedestal_down(t_camera *cam, float_t meters);

//closest_hit.c
void			get_closest_hit(t_scene *scene,
					t_ray ray, t_hit_info *hit_info);
int				is_in_fornt_of_light(t_scene *scene,
					t_ray ray, float_t distance_t);
t_lst			*get_closest_hit_light(t_scene *scene, t_ray ray);
float_t			get_distance_t(t_lst *object, t_ray ray, t_hit_info *hit_info);
t_color			get_color_hitpoint(t_scene *scene,
					t_lst *object, t_hit_info *hit_info);

//cylinder.c
int				split_parameter_cyl(char *line, char ***param);
int				assign_parameter_cyl(char ***param,
					char ***orig, char ***axis, char ***color);
t_cylinder		*create_cylinder(char **param,
					char **orig, char **axis, char **color);
void			free_all_cyl(char **param,
					char **orig, char **axis, char **color);
int				add_cylinder(t_lst_ref *objects, char *line);

//colors_calc.c
t_color			color_mult(t_color color, float_t factor);
t_color			color_add(t_color color1, t_color color2);
t_color			color_mult_color(t_color color1, t_color color2);
t_color			color_add_factor(t_color color, float_t factor);
t_color			color_div(t_color color, float_t div);

//colors.c
int				color_conversion(t_color color);
t_color			get_color_from_str_arr(char **str);
t_color			color_mix(t_color obj_color, t_color light_color);
t_color			color_clamp(t_color color, float_t min, float_t max);

//cylinder_intersect.c
float_t			get_cyl_distance_t_proj(t_cylinder *cyl,
					t_ray ray, t_hit_info *hit);
float_t			find_top_cap_intersection(t_cylinder *cylinder, t_ray ray);
float_t			find_bottom_cap_intersection(t_cylinder *cylinder, t_ray ray);
float_t			get_cyl_distance_t(t_cylinder *cyl, t_ray ray, t_hit_info *hit);

//cylinder_normal.c
void			get_normal_cylinder(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_proj(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_top_cap(t_hit_info *hit_info, t_cylinder *cylinder);
void			normal_cyl_bottom_cap(t_hit_info *hit_info,
					t_cylinder *cylinder);

//cylinder.c

//data.c
t_data			*init_data(void);
void			*free_data_null(t_data *data);

//diffuse_light.c
t_color			diffuse_light_obj(t_scene *scene, t_lst *obj, t_hit_info *hit);
t_color			diffuse_light_sphere(t_scene *scene,
					t_sphere *sphere, t_hit_info *hit);
t_color			diffuse_light_plane(t_scene *scene,
					t_plane *plane, t_hit_info *hit);
t_color			diffuse_light_cyl(t_scene *scene,
					t_cylinder *cyl, t_hit_info *hit);

//fill_scene.c
int				fill_cam_light(t_scene *scene, t_lst *runner,
					t_resolution win, char *line);
int				fill_obj(t_scene *scene, t_lst *runner,
					t_resolution win, char *line);
int				fill_scene(t_scene *scene, t_lst_ref *scene_lines,
					t_resolution win);
float_t			get_reflect_factor_from_str(char *str);

//follow_ray.c
t_color			follow_ray(t_scene *scene, t_ray ray);
t_vec3			calulate_fuzzed_reflected(t_vec3 direction,
					t_vec3 normal, double fuzz);
float_t			get_reflect_factor(t_lst *object);
void			get_normal_to_surface(t_lst *object, t_hit_info *hit_info);
t_vec3			get_reflect_ray(t_vec3 vector, t_vec3 normal);

//free.c
void			*free_null(void *ptr);
void			*free_arr_null(char **arr);

//ft_atof.c
double			ft_atof(const char *str);

//hooks_obj_actions.c
void			object_rotate(int keysym, t_data *data);
void			object_resize(int keysym, t_data *data);
void			object_translate(int keysym, t_data *data);
void			object_actions(int keysym, t_data *data);
void			select_next_object(t_data *data);

//hooks_resize_obj1.c
void			increase_diameter_sphere(t_lst *object);
void			decrease_diameter_sphere(t_lst *object);
void			increase_diameter_cylinder(t_lst *object);
void			decrease_diameter_cylinder(t_lst *object);
void			increase_hight_cylinder(t_lst *object);

//hooks_resize_obj2.c
void			decrease_hight_cylinder(t_lst *object);
void			object_resize_up(t_lst *object);
void			object_resize_down(t_lst *object);
void			object_resize_left(t_lst *object);
void			object_resize_right(t_lst *object);

//hooks_rotate_obj1.c
void			rotate_obj_inc_x(t_lst *object);
void			rotate_obj_dec_x(t_lst *object);
void			rotate_obj_inc_y(t_lst *object);

//hooks_rotate_obj2.c
void			rotate_obj_dec_y(t_lst *object);
void			rotate_obj_inc_z(t_lst *object);
void			rotate_obj_dec_z(t_lst *object);

//hooks_scene_actions.c
void			light_actions(int keysym, t_data *data);
void			camera_actions(int keysym, t_data *data);
void			scene_actions(int keysym, t_data *data);

//hooks_translate_obj1.c
void			translate_obj_inc_x(t_lst *object);
void			translate_obj_dec_x(t_lst *object);
void			translate_obj_inc_y(t_lst *object);

//hooks_translate_obj2.c
void			translate_obj_dec_y(t_lst *object);
void			translate_obj_inc_z(t_lst *object);
void			translate_obj_dec_z(t_lst *object);

//hooks.c
int				loop_hook(t_data *data);
int				key_hook1(int keysym, t_data *data);
int				close_app(t_data *data);
void			init_pixelcolors(t_data *data);
int				start_mlx(t_data *data);

//light_angle.c
float_t			get_light_angle(t_vec3 hit_point,
					t_sphere *sphere, t_scene *scene);
float_t			get_light_angle_plane(t_vec3 hit_point,
					t_plane *plane, t_scene *scene);
float_t			get_light_angle_cyl(t_hit_info *hit_info,
					t_cylinder *cyl, t_scene *scene);

//light.c
void			free_light(char **param, char **orig, char **color);
char			**handle_orig_and_color_light(char **orig, char **param);
int				fill_light_data(t_light *light, char **orig,
					char **param, char **color);
t_light			*init_light(char *line);
void			translate_light(t_light *light, t_vec3 vec);

//linked_list1.c
t_lst			*ft_lstlast(t_lst *lst);
t_lst			*ft_lstnew(void *content);
void			ft_add_lst_last(t_lst *new_entry, t_lst_ref *lst_ref);

//linked_list2.c
void			ft_add_lst_head(t_lst *new_entry, t_lst_ref *lst_ref);
void			clear_lst(t_lst_ref *lst_ref);
void			*free_lst_null(t_lst_ref *lst_ref);

//malloc_safe.c
void			*malloc_or_print_error(size_t size);
void			*calloc_or_print_error(size_t count, size_t size);

//math_helper.c
float_t			clamp(float_t value, float_t min, float_t max);
float_t			deg_to_rad(float_t deg);

//matrix.c
t_vec3			rotate_x(t_vec3 vec, float_t angle);
t_vec3			rotate_y(t_vec3 vec, float_t angle);
t_vec3			rotate_z(t_vec3 vec, float_t angle);
t_mat3x3		get_rot_x(float_t angle);
t_vec3			mat_mult(t_mat3x3 mat, t_vec3 vec);
t_mat3x3		mat3x3_dot_prod(t_mat3x3 a, t_mat3x3 b);

//planes_utils.c
void			free_values_plane(char ***param,
					char ***point, char ***normal_vec, char ***color);
int				split_parameter_plane(char *line, char ***param);
void			add_plane_list(t_lst_ref *objects, t_plane *plane);

//plane.c
int				get_values_plane(char ***param,
					char ***point, char ***normal_vec, char ***color);
int				assign_values_plane(t_plane *plane,
					char **point, char **normal_vec, char **color);
int				add_plane(t_lst_ref *objects, char *line);

//random.c
float_t			random_float(void);
t_vec3			vector(float_t x, float_t y, float_t z);
float_t			random_from(float_t min, float_t max);
t_vec3			random_vector_in(float_t min, float_t max);
t_vec3			random_in_unit_sphere(void);

//rays.c
t_pt3			ray_point_at(t_ray ray, float_t t);

//read_file.c
void			wrapper_open(char *file, int *fd);
void			wrapper_close(int *fd);
t_lst_ref		*read_file(char *file);

//render_plane.c
float_t			get_plane_distance_t(t_lst *object, t_ray ray);

//render.c
void			img_pix_put(t_data *data, int x, int y, int color);
t_ray			get_ray_offset(t_camera *cam, float_t u, float_t v);
int				mult_sample_color(t_data *data, t_color color, int i, int j);
void			render_scene(t_data *data);
void			render_background(t_data *data, int color);

//scene.c
t_scene			*init_scene(void);
void			*free_scene_null(t_scene *scene);

//specular_light_helper.c
t_vec3			reflect_vec_sphere(t_vec3 hit_point,
					t_sphere *sphere, t_scene *scene);
t_vec3			reflect_vec_plane(t_vec3 hit_point,
					t_plane *plane, t_scene *scene);
t_vec3			reflect_vec_cyl(t_hit_info *hit_info,
					t_cylinder *cyl, t_scene *scene);
int				check_in_shade(t_hit_info *hit_info, t_scene *scene);

//specular_light.c
t_color			specular_light_obj(t_scene *scene,
					t_lst *object, t_hit_info *hit_info);
t_color			specular_light_plane(t_scene *scene,
					t_plane *plane, t_hit_info *hit_info);
t_color			specular_light_cyl(t_scene *scene,
					t_cylinder *cyl, t_hit_info *hit_info);
t_color			specular_light_sphere(t_scene *scene,
					t_sphere *sphere, t_hit_info *hit_info);

//sphere.c
int				split_param_sphere(char *line,
					char ***param, char ***orig, char ***color);
t_sphere		*create_sphere(char **param, char **orig, char **color);
int				add_sphere(t_lst_ref *objects, char *line);
float_t			get_sphere_distance_t(t_lst *object,
					t_ray ray, t_hit_info *hit_info);
int				calc_distant_t(t_hit_calc *calc, t_hit_info *hit_info);

//vector_helper.c
t_vec3			get_vec_from_str_arr(char **str);

//vector_operations1.c
t_vec3			vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec_mult(t_vec3 vec, float_t factor);
t_vec3			vec_div(t_vec3 vec, float_t factor);

//vector_operations2.c
float_t			scalar_prod(t_vec3 vec1, t_vec3 vec2);
t_vec3			cross_prod(t_vec3 vec1, t_vec3 vec2);
float_t			vec_length(t_vec3 vec);
t_vec3			unit_vec3(t_vec3 vec);
int				vec_cmp(t_vec3 vec1, t_vec3 vec2);

#endif