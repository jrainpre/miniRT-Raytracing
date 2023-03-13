#include "miniRT.h"

t_vec3	get_vec_from_str_arr(char **str)
{
	t_vec3	vec;

	vec.x = ft_atof(str[0]);
	vec.y = ft_atof(str[1]);
	vec.z = ft_atof(str[2]);
	return (vec);
}
