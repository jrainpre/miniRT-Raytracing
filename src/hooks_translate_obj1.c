#include "miniRT.h"

void	translate_obj_inc_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x += 0.1;
}

void	translate_obj_dec_x(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.x -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.x -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.x -= 0.1;
}

void	translate_obj_inc_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y += 0.1;
}
