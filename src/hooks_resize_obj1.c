#include "miniRT.h"

void	increase_diameter_sphere(t_lst *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	sphere->radius += 0.1;
}

void	decrease_diameter_sphere(t_lst *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	if (sphere->radius > 0.1)
		sphere->radius -= 0.1;
}

void	increase_diameter_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	cylinder->radius += 0.1;
}

void	decrease_diameter_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	if (cylinder->radius > 0.1)
		cylinder->radius -= 0.1;
}

void	increase_hight_cylinder(t_lst *object)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object;
	cylinder->height += 0.1;
}
