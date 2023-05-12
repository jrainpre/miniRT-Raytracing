#include "miniRT.h"

void	translate_obj_dec_y(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.y -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.y -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.y -= 0.1;
}

void	translate_obj_inc_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z += 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z += 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z += 0.1;
}

void	translate_obj_dec_z(t_lst *object)
{
	if (object->type == SPHERE)
		((t_sphere *)object->content)->orig.z -= 0.1;
	if (object->type == CYLINDER)
		((t_cylinder *)object->content)->orig.z -= 0.1;
	if (object->type == PLANE)
		((t_plane *)object->content)->point.z -= 0.1;
}
