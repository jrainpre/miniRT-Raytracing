#include "miniRT.h"

t_p_state	plane_transition(t_p_state state, char c)
{
	if (state == P_START)
	{
		if (c == ' ')
			return (P_START);
		if (c == 'p')
			return (P_IDENTIFIER_1);
	}
	else if (state == P_IDENTIFIER_1)
	{
		if (c == 'l')
			return (P_IDENTIFIER_2);
	}
	else if (state == P_IDENTIFIER_2)
	{
		if (c == ' ')
			return (P_SPACE_1);
	}
	else if (state == P_SPACE_1)
	{
		if (c == ' ')
			return (P_SPACE_1);
		if (c == '-')
			return (P_ORIG_X_SIGN);
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_1);
		if (c == '.')
			return (P_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_1);
		if (ft_isdigit(c))
			return (P_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_1)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-')
			return (P_ORIG_Y_SIGN);
	}
	else if (state == P_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_2);
		if (c == '.')
			return (P_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_2);
		if (ft_isdigit(c))
			return (P_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_2)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-')
			return (P_ORIG_Z_SIGN);
	}
	else if (state == P_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (c == '.')
			return (P_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (P_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == P_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == P_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (ft_isdigit(c))
			return (P_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == P_SPACE_2)
	{
		if (c == ' ')
			return (P_SPACE_2);
		if (ft_isdigit(c))
			return (P_NORMAL_X_BEFORE_DECIMAL);
		if (c == ' ')
			return (P_NORMAL_X_SIGN);
	}
	else if (state == P_NORMAL_X_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_X_BEFORE_DECIMAL);
	}
	else if (state == P_NORMAL_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_3);
		if (c == '.')
			return (P_NORMAL_X_DECIMAL);
	}
	else if (state == P_NORMAL_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_X_AFTER_DECIMAL);
	}
	else if (state == P_NORMAL_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_3);
		if (ft_isdigit(c))
			return (P_NORMAL_X_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_3)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_BEFORE_DECIMAL);
		if (c == '-')
			return (P_NORMAL_Y_SIGN);
	}
	else if (state == P_NORMAL_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_BEFORE_DECIMAL);
	}
	else if (state == P_NORMAL_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_4);
		if (c == '.')
			return (P_NORMAL_Y_DECIMAL);
	}
	else if (state == P_NORMAL_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Y_AFTER_DECIMAL);
	}
	else if (state == P_NORMAL_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (P_COMMA_4);
		if (ft_isdigit(c))
			return (P_NORMAL_Y_AFTER_DECIMAL);
	}
	else if (state == P_COMMA_4)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_BEFORE_DECIMAL);
		if (c == '-')
			return (P_NORMAL_Z_SIGN);
	}
	else if (state == P_NORMAL_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_BEFORE_DECIMAL);
	}
	else if (state == P_NORMAL_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (c == '.')
			return (P_NORMAL_Z_DECIMAL);
	}
	else if (state == P_NORMAL_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (P_NORMAL_Z_AFTER_DECIMAL);
	}
	else if (state == P_NORMAL_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (ft_isdigit(c))
			return (P_NORMAL_Z_AFTER_DECIMAL);
	}
	else if (state == P_SPACE_3)
	{
		if (c == ' ')
			return (P_SPACE_3);
		if (ft_isdigit(c))
			return (P_RED);
	}
	else if (state == P_RED)
	{
		if (c == ',')
			return (P_COMMA_5);
		if (ft_isdigit(c))
			return (P_RED);
	}
	else if (state == P_COMMA_5)
	{
		if (ft_isdigit(c))
			return (P_GREEN);
	}
	else if (state == P_GREEN)
	{
		if (c == ',')
			return (P_COMMA_6);
		if (ft_isdigit(c))
			return (P_GREEN);
	}
	else if (state == P_COMMA_6)
	{
		if (ft_isdigit(c))
			return (P_BLUE);
	}
	else if (state == P_BLUE)
	{
		if (ft_isdigit(c))
			return (P_BLUE);
		if (c == '\n')
			return (P_ACCEPT);
		if (c == ' ')
			return (P_SPACE_4);
	}
	else if (state == P_SPACE_4)
	{
		if (c == ' ')
			return (P_SPACE_4);
		if (c == '\n')
			return (P_ACCEPT);
	}
	else if (state == P_ACCEPT)
		return (P_ACCEPT);
	return (P_REJECT);
}

int	is_valid_plane(char *line)
{
	t_p_state	state;
	int			i;

	i = 0;
	state = P_START;
	while (line[i])
	{
		state = plane_transition(state, line[i]);
		if (state == P_REJECT)
			break ;
		i++;
	}
	if (state == P_ACCEPT || state == P_BLUE || state == P_SPACE_4)
		return (1);
	ft_putstr_fd("Error\nPlane could not be parsed\n", STDERR_FILENO);
	return (0);
}
