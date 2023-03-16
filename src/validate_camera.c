#include "miniRT.h"



t_c_state	camera_transition(t_c_state state, char c)
{
	if (state == C_START)
	{
		if (c == ' ')
			return (C_START);
		if (c == 'C')
			return (C_IDENTIFIER_1);
	}
	else if (state == C_IDENTIFIER_1)
	{
		if (c == ' ')
			return (C_SPACE_1);
	}
	else if (state == C_SPACE_1)
	{
		if (c == ' ')
			return (C_SPACE_1);
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_X_SIGN);
	}
	else if (state == C_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_1);
		if (c == '.')
			return (C_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == C_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_1);
		if (ft_isdigit(c))
			return (C_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == C_COMMA_1)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_Y_SIGN);
	}
	else if (state == C_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_2);
		if (c == '.')
			return (C_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == C_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (C_COMMA_2);
		if (ft_isdigit(c))
			return (C_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == C_COMMA_2)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIG_Z_SIGN);
	}
	else if (state == C_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (c == '.')
			return (C_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (C_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == C_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (C_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == C_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (ft_isdigit(c))
			return (C_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == C_SPACE_2)
	{
		if (c == ' ')
			return (C_SPACE_2);
		if (ft_isdigit(c))
			return (C_ORIENTATION_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (C_ORIENTATION_X_SIGN);
	}
	else if (state == C_ORIENTATION_X_SIGN)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_X_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_X_BEFORE_DECIMAL)
		{
			if (c == ',')
				return (C_COMMA_3);
			if (c == '.')
				return (C_ORIENTATION_X_DECIMAL);
			if (ft_isdigit(c))
				return (C_ORIENTATION_X_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_X_DECIMAL)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_X_AFTER_DECIMAL);
		}
		else if (state == C_ORIENTATION_X_AFTER_DECIMAL)
		{
			if (c == ',')
				return (C_COMMA_3);
			if (ft_isdigit(c))
				return (C_ORIENTATION_X_AFTER_DECIMAL);
		}
		else if (state == C_COMMA_3)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Y_BEFORE_DECIMAL);
			if (c == '-' || c == '+')
				return (C_ORIENTATION_Y_SIGN);
		}
		else if (state == C_ORIENTATION_Y_SIGN)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Y_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_Y_BEFORE_DECIMAL)
		{
			if (c == ',')
				return (C_COMMA_4);
			if (c == '.')
				return (C_ORIENTATION_Y_DECIMAL);
			if (ft_isdigit(c))
				return (C_ORIENTATION_Y_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_Y_DECIMAL)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Y_AFTER_DECIMAL);
		}
		else if (state == C_ORIENTATION_Y_AFTER_DECIMAL)
		{
			if (c == ',')
				return (C_COMMA_4);
			if (ft_isdigit(c))
				return (C_ORIENTATION_Y_AFTER_DECIMAL);
		}
			else if (state == C_COMMA_4)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Z_BEFORE_DECIMAL);
			if (c == '-' || c == '+')
				return (C_ORIENTATION_Z_SIGN);
		}
		else if (state == C_ORIENTATION_Z_SIGN)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Z_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_Z_BEFORE_DECIMAL)
		{
			if (c == ' ')
				return (C_SPACE_3);
			if (c == '.')
				return (C_ORIENTATION_Z_DECIMAL);
			if (ft_isdigit(c))
				return (C_ORIENTATION_Z_BEFORE_DECIMAL);
		}
		else if (state == C_ORIENTATION_Z_DECIMAL)
		{
			if (ft_isdigit(c))
				return (C_ORIENTATION_Z_AFTER_DECIMAL);
		}
		else if (state == C_ORIENTATION_Z_AFTER_DECIMAL)
		{
			if (c == ' ')
				return (C_SPACE_3);
			if (ft_isdigit(c))
				return (C_ORIENTATION_Z_AFTER_DECIMAL);
		}
			else if (state == C_SPACE_3)
		{
			if (c == ' ')
				return (C_SPACE_3);
			if (ft_isdigit(c))
				return (C_FOV_BEFORE_DECIMAL);
		}
		else if (state == C_FOV_BEFORE_DECIMAL)
		{
			if (c == '.')
				return (C_FOV_DECIMAL);
			if (ft_isdigit(c))
				return (C_FOV_BEFORE_DECIMAL);
			if (c == ' ')
				return (C_SPACE_4);
			if(c == '\n')
				return(C_ACCEPT);
		}
		else if (state == C_FOV_DECIMAL)
		{
			if (ft_isdigit(c))
				return (C_FOV_AFTER_DECIMAL);
		}
		else if (state == C_FOV_AFTER_DECIMAL)
		{
			if (ft_isdigit(c))
				return (C_FOV_AFTER_DECIMAL);
			if (c == ' ')
				return(C_SPACE_4);
		}
		else if (state == C_SPACE_4)
		{
			if (c == ' ')
				return(C_SPACE_4);
			if (c == '\n')
				return(C_ACCEPT);
		}
		else if (state == C_ACCEPT)
			return (C_ACCEPT);
		return(C_REJECT);
}

int	is_valid_camera(char *line)
{
	t_c_state	state;
	int			i;

	i = 0;
	state = C_START;
	while (line[i])
	{
		state = camera_transition(state, line[i]);
		if (state == CY_REJECT)
			break ;
		i++;
	}
	if (state == C_ACCEPT || state == C_FOV_AFTER_DECIMAL || state == C_FOV_BEFORE_DECIMAL || state == C_SPACE_4)
		return (1);
	ft_putstr_fd("Error\nCamera could not be parsed\n", STDERR_FILENO);
	return (0);
}
