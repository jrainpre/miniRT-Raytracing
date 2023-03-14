#ifndef FUNCTION_TESTS_H
# define FUNCTION_TESTS_H

# include "image.h"
# include "linked_list.h"

void	vector_test(void);
void	ray_test(void);
void	background_test(t_data *data);
void	print_color(char *title, t_color color);
void	print_vec3(char *title, t_vec3 vec);
void	print_object(void *object, t_object_type type);
void	test_mat_dot_prod(void);

#endif