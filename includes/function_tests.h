#ifndef FUNCTION_TESTS_H
# define FUNCTION_TESTS_H

# include "image.h"

void	vector_test(void);
void	ray_test(void);
void	background_test(t_data *data);
void	print_color(char *title, t_color color);
void	print_pt3_or_vec3(char *title, t_pt3 pt);

#endif