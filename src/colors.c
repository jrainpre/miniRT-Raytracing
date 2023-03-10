#include "miniRT.h"

int color_conversion(t_color color)
{
	u_int8_t r;
	u_int8_t g;
	u_int8_t b;
	u_int8_t a;

	r = (u_int8_t)(color.x * 255.0f);
	g = (u_int8_t)(color.y * 255.0f);
	b = (u_int8_t)(color.z * 255.0f);
	a = (u_int8_t)(color.a * 255.0f);
	return (a << 24 | b << 16 | g << 8 | r);
}