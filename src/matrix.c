#include "miniRT.h"

t_vec3	rotate_x(t_vec3 vec, float_t angle)
{
	t_mat3x3	rot_x;

	rot_x = (t_mat3x3){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	return (mat_mult(rot_x, vec));
}

t_vec3	rotate_y(t_vec3 vec, float_t angle)
{
	t_mat3x3	rot_y;

	rot_y = (t_mat3x3){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	return (mat_mult(rot_y, vec));
}

t_vec3	rotate_z(t_vec3 vec, float_t angle)
{
	t_mat3x3	rot_z;

	rot_z = (t_mat3x3){
		cos(angle), -sin(angle), 0,
		sin(angle), cos(angle), 0,
		0, 0, 1};
	return (mat_mult(rot_z, vec));
}

t_mat3x3	get_rot_x(float_t angle)
{
	t_mat3x3	rot_x;

	rot_x = (t_mat3x3){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	return (rot_x);
}
