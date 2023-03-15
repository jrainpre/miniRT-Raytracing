#include "miniRT.h"

/*
Deterministic Finite Automaton:
https://automatonsimulator.com/#%7B%22type%22%3A%22DFA%22%2C%22dfa%22%3A%7B%22transitions%22%3A%7B%22start%22%3A%7B%22%20%22%3A%22start%22%2C%22A%22%3A%22s1%22%2C%22n%22%3A%22s6%22%2C%22p%22%3A%22s5%22%2C%22s%22%3A%22s4%22%2C%22C%22%3A%22s3%22%2C%22L%22%3A%22s2%22%2C%22c%22%3A%22s7%22%2C%22x%22%3A%22s8%22%7D%7D%2C%22startState%22%3A%22start%22%2C%22acceptStates%22%3A%5B%22s1%22%2C%22s3%22%2C%22s2%22%2C%22s4%22%2C%22s5%22%2C%22s7%22%2C%22s6%22%5D%7D%2C%22states%22%3A%7B%22start%22%3A%7B%7D%2C%22s1%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A86%2C%22left%22%3A282%2C%22displayId%22%3A%22LINE_AMBIENT_LIGHT%22%7D%2C%22s6%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A460%2C%22left%22%3A14%2C%22displayId%22%3A%22LINE_NEW_LINE%22%7D%2C%22s5%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A366%2C%22left%22%3A283%2C%22displayId%22%3A%22LINE_PLANE%22%7D%2C%22s4%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A281%2C%22left%22%3A282%2C%22displayId%22%3A%22LINE_SPHERE%22%7D%2C%22s3%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A154%2C%22left%22%3A283%2C%22displayId%22%3A%22LINE_CAMERA%22%7D%2C%22s2%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A216%2C%22left%22%3A283%2C%22displayId%22%3A%22LINE_LIGHT%22%7D%2C%22s7%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A461%2C%22left%22%3A279%2C%22displayId%22%3A%22LINE_CYLINDER%22%7D%2C%22s8%22%3A%7B%22top%22%3A582%2C%22left%22%3A234%2C%22displayId%22%3A%22LINE_REJECT%22%7D%7D%2C%22transitions%22%3A%5B%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22start%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22A%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22p%22%2C%22stateB%22%3A%22s5%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22s%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22C%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22L%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22c%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s8%22%7D%5D%2C%22bulkTests%22%3A%7B%22accept%22%3A%22%22%2C%22reject%22%3A%22%22%7D%7D
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
