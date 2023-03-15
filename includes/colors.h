#ifndef COLORS_H
# define COLORS_H

# include "vector.h"

# define RED	0x00FF0000
# define DRED	0x00660000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define DBLUE	0x00000066
# define PURPLE	0x00B491C8
# define WHITE	0x00FFFFFF
# define DGREEN	0x00006600
# define BLACK	0x00000000
# define GREY	0x00888888
# define DGREY	0x00333333
# define NOCOLOR	0x00000000

typedef struct s_color
{
	float_t r;
	float_t g;
	float_t b;
	float_t a;
}				t_color;

int color_conversion(t_color color);
t_color color_mix(t_color obj_color, t_color light_color);
t_color color_mult(t_color vec, float_t factor);
t_color color_clamp(t_color vec, float_t min, float_t max);
t_color color_add(t_color vec1, t_color vec2);
t_color color_mult_color(t_color color1, t_color color2);
t_color color_add_factor(t_color vec, float_t factor);
t_color mix_light(t_color act_color, t_color obj_color, t_color light_color, float_t ratio);


#endif
