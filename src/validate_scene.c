#include "miniRT.h"

/*
Deterministic Finite Automaton:
*/

t_line_state	line_transition(t_line_state state, char c)
{
	if (state == LINE_START)
	{
		if (c == ' ')
			return (LINE_START);
		if (c == '\n')
			return (LINE_NEW_LINE);
		if (c == 'A')
			return (LINE_AMBIENT_LIGHT);
		if (c == 'C')
			return (LINE_CAMERA);
		if (c == 'L')
			return (LINE_LIGHT);
		if (c == 's')
			return (LINE_SPHERE);
		if (c == 'p')
			return (LINE_PLANE);
		if (c == 'c')
			return (LINE_CYLINDER);
	}
	return (LINE_REJECT);
}

int	is_valid_scene(char **scene_arr)
{
	t_line_state	state;
	int				i;
	int				j;
	int				cameras;
	int				lights;
	int				ambient_lights;
	int				objects;

	cameras = 0;
	lights = 0;
	ambient_lights = 0;
	objects = 0;
	j = 0;
	while (scene_arr[j])
	{
		state = LINE_START;
		i = 0;
		while (scene_arr[j][i])
		{
			state = line_transition(state, scene_arr[j][i]);
			if (state == LINE_AMBIENT_LIGHT)
			{
				ambient_lights++;
				if (!is_valid_ambient_light(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_CAMERA)
			{
				cameras++;
				if (!is_valid_camera(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_LIGHT)
			{
				lights++;
				if (!is_valid_light(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_SPHERE)
			{
				objects++;
				if (!is_valid_sphere(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_PLANE)
			{
				objects++;
				if (!is_valid_plane(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_CYLINDER)
			{
				objects++;
				if (!is_valid_cylinder(scene_arr[j]))
					return (0);
				break ;
			}
			else if (state == LINE_REJECT)
				return (0);
			else if (state == LINE_NEW_LINE)
				break ;
			i++;
		}
		j++;
	}
	if (cameras != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one camera\n", STDERR_FILENO);
		return (0);
	}
	if (lights != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one light\n", STDERR_FILENO);
		return (0);
	}
	if (ambient_lights != 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected one ambient light\n", STDERR_FILENO);
		return (0);
	}
	if (objects < 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Expected at least one object\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
