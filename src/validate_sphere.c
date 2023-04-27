#include "miniRT.h"

t_s_state	sphere_transition(t_s_state state, char c)
{
	if (state == S_START)
	{
		if (c == ' ')
			return (S_START);
		if (c == 's')
			return (S_IDENTIFIER_1);
	}
	else if (state == S_IDENTIFIER_1)
	{
		if (c == 'p')
			return (S_IDENTIFIER_2);
	}
	else if (state == S_IDENTIFIER_2)
	{
		if (c == ' ')
			return (S_SPACE_1);
	}
	else if (state == S_SPACE_1)
	{
		if (c == ' ')
			return (S_SPACE_1);
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_X_SIGN);
	}
	else if (state == S_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_1);
		if (c == '.')
			return (S_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_1);
		if (ft_isdigit(c))
			return (S_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == S_COMMA_1)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_Y_SIGN);
	}
	else if (state == S_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_2);
		if (c == '.')
			return (S_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (S_COMMA_2);
		if (ft_isdigit(c))
			return (S_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == S_COMMA_2)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (S_ORIG_Z_SIGN);
	}
	else if (state == S_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (c == '.')
			return (S_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (S_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == S_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == S_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (ft_isdigit(c))
			return (S_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == S_SPACE_2)
	{
		if (c == ' ')
			return (S_SPACE_2);
		if (ft_isdigit(c))
			return (S_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == S_DIAMETER_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (c == '.')
			return (S_DIAMETER_DECIMAL);
		if (ft_isdigit(c))
			return (S_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == S_DIAMETER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (S_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == S_DIAMETER_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (ft_isdigit(c))
			return (S_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == S_SPACE_3)
	{
		if (c == ' ')
			return (S_SPACE_3);
		if (ft_isdigit(c))
			return (S_RED);
	}
	else if (state == S_RED)
	{
		if (c == ',')
			return (S_COMMA_3);
		if (ft_isdigit(c))
			return (S_RED);
	}
	else if (state == S_COMMA_3)
	{
		if (ft_isdigit(c))
			return (S_GREEN);
	}
	else if (state == S_GREEN)
	{
		if (c == ',')
			return (S_COMMA_4);
		if (ft_isdigit(c))
			return (S_GREEN);
	}
	else if (state == S_COMMA_4)
	{
		if (ft_isdigit(c))
			return (S_BLUE);
	}
	else if (state == S_BLUE)
	{
		if (ft_isdigit(c))
			return (S_BLUE);
		if (c == '\n')
			return (S_ACCEPT);
		if (c == ' ')
			return (S_SPACE_4);
	}
	else if (state == S_SPACE_4)
	{
		if (c == ' ')
			return (S_SPACE_4);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_REFLECTIVENESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (c == '.')
			return (S_REFLECTIVENESS_DECIMAL);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_SPACE_5)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_BEFORE_DECIMAL);
		if (c == '.')
			return (S_REFLECTIVENESS_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_REFLECTIVENESS_DECIMAL)
	{
		if(ft_isdigit(c))
			return (S_REFLECTIVENESS_AFTER_DECIMAL);
	}
	else if (state == S_REFLECTIVENESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (S_SPACE_5);
		if (ft_isdigit(c))
			return (S_REFLECTIVENESS_AFTER_DECIMAL);
		if (c == '\n')
			return (S_ACCEPT);
	}
	else if (state == S_ACCEPT)
		return (S_ACCEPT);
	return (S_REJECT);
}

int	is_valid_sphere(char *line)
{
	t_s_state	state;
	int			i;

	i = 0;
	state = S_START;
	while (line[i])
	{
		state = sphere_transition(state, line[i]);
		if (state == S_REJECT)
			break ;
		i++;
	}
	if (state == S_ACCEPT || state == S_SPACE_4 || state == S_BLUE || state == S_REFLECTIVENESS_AFTER_DECIMAL || state == S_SPACE_5 || state == S_REFLECTIVENESS_BEFORE_DECIMAL)
		return (1);
	ft_putstr_fd("Error\nSphere could not be parsed\n", STDERR_FILENO);
	return (0);
}
