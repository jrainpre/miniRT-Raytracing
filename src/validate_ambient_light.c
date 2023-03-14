#include "miniRT.h"

t_a_state	ambient_light_transition(t_a_state state, char c)
{
	if (state == A_START)
	{
		if (c == ' ')
			return (A_START);
		if (c == 'A')
			return (A_IDENTIFIER);
		return (A_REJECT);
	}
	if (state == A_IDENTIFIER)
	{
		if (c == ' ')
			return (A_SPACE_1);
		return (A_REJECT);
	}
	return (A_REJECT);
}

int	is_valid_ambient_light(char *line)
{
	t_a_state	state;
	int			i;

	i = 0;
	state = A_START;
	while (line[i])
	{
		state = ambient_light_transition(state, line[i]);
		if (state == A_REJECT)
			break ;
		i++;
	}
	if (state == A_ACCEPT)
		return (0);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}
