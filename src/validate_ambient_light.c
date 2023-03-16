#include "miniRT.h"

t_a_state	ambient_light_transition(t_a_state state, char c)
{
	if (state == A_START)
	{
		if (c == ' ')
			return (A_START);
		if (c == 'A')
			return (A_IDENTIFIER);
	}
	else if (state == A_IDENTIFIER)
	{
		if (c == ' ')
			return (A_SPACE_1);
	}
	else if (state == A_SPACE_1)
	{
		if (c == ' ')
			return (A_SPACE_1);
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_BEFORE_DECIMAL);
	}
	else if (state == A_LIGHT_RATIO_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (c == '.')
			return (A_LIGHT_RATIO_DECIMAL);
	}
	else if (state == A_LIGHT_RATIO_DECIMAL)
	{
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_AFTER_DECIMAL);
	}
	else if (state == A_LIGHT_RATIO_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (ft_isdigit(c))
			return (A_LIGHT_RATIO_AFTER_DECIMAL);
	}
	else if (state == A_SPACE_2)
	{
		if (c == ' ')
			return (A_SPACE_2);
		if (ft_isdigit(c))
			return (A_RED);
	}
	else if (state == A_RED)
	{
		if (c == ',')
			return (A_COMMA_1);
		if (ft_isdigit(c))
			return (A_RED);
	}
	else if (state == A_COMMA_1)
	{
		if (ft_isdigit(c))
			return (A_GREEN);
	}
	else if (state == A_GREEN)
	{
		if (c == ',')
			return (A_COMMA_2);
		if (ft_isdigit(c))
			return (A_GREEN);
	}
	else if (state == A_COMMA_2)
	{
		if (ft_isdigit(c))
			return (A_BLUE);
	}
	else if (state == A_BLUE)
	{
		if (ft_isdigit(c))
			return (A_BLUE);
		if (c == '\n')
			return (A_ACCEPT);
		if (c == ' ')
			return (A_SPACE_3);
	}
	else if (state == A_SPACE_3)
	{
		if (c == ' ')
			return (A_SPACE_3);
		if (c == '\n')
			return (A_ACCEPT);
	}
	else if (state == A_ACCEPT)
		return (A_ACCEPT);
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
	if (state == A_ACCEPT || state == A_BLUE || state == A_SPACE_3)
		return (1);
	ft_putstr_fd("Error\nAmbient light could not be parsed\n", STDERR_FILENO);
	return (0);
}
