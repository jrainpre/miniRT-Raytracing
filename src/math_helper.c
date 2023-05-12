#include "miniRT.h"

float_t	clamp(float_t value, float_t min, float_t max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float_t	deg_to_rad(float_t deg)
{
	return (deg * (M_PI / 180.0));
}