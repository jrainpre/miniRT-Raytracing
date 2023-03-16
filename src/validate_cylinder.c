#include "miniRT.h"

t_cy_state	cylinder_transition(t_cy_state state, char c)
{
	if (state == CY_START)
	{
		if (c == ' ')
			return (CY_START);
		if (c == 'c')
			return (CY_IDENTIFIER_1);
	}
	else if (state == CY_IDENTIFIER_1)
	{
		if (c == 'y')
			return (CY_IDENTIFIER_2);
	}
	else if (state == CY_IDENTIFIER_2)
	{
		if (c == ' ')
			return (CY_SPACE_1);
	}
	else if (state == CY_SPACE_1)
	{
		if (c == ' ')
			return (CY_SPACE_1);
		if (c == '-' || c == '+')
			return (CY_ORIG_X_SIGN);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (c == '.')
			return (CY_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_1);
		if (ft_isdigit(c))
			return (CY_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_1)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_ORIG_Y_SIGN);
	}
	else if (state == CY_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (c == '.')
			return (CY_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_2)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_ORIG_Z_SIGN);
	}
	else if (state == CY_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (c == '.')
			return (CY_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_2)
	{
		if (c == ' ')
			return (CY_SPACE_2);
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
		if (c == ' ')
			return (CY_AXIS_X_SIGN);
	}
	else if (state == CY_AXIS_X_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (c == '.')
			return (CY_AXIS_X_DECIMAL);
	}
	else if (state == CY_AXIS_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_3);
		if (ft_isdigit(c))
			return (CY_AXIS_X_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_3)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_AXIS_Y_SIGN);
	}
	else if (state == CY_AXIS_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (c == '.')
			return (CY_AXIS_Y_DECIMAL);
	}
	else if (state == CY_AXIS_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (CY_COMMA_4);
		if (ft_isdigit(c))
			return (CY_AXIS_Y_AFTER_DECIMAL);
	}
	else if (state == CY_COMMA_4)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (CY_AXIS_Z_SIGN);
	}
	else if (state == CY_AXIS_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_BEFORE_DECIMAL);
	}
	else if (state == CY_AXIS_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (c == '.')
			return (CY_AXIS_Z_DECIMAL);
	}
	else if (state == CY_AXIS_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	else if (state == CY_AXIS_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_AXIS_Z_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_3)
	{
		if (c == ' ')
			return (CY_SPACE_3);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (c == '.')
			return (CY_DIAMETER_DECIMAL);
		if (ft_isdigit(c))
			return (CY_DIAMETER_BEFORE_DECIMAL);
	}
	else if (state == CY_DIAMETER_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == CY_DIAMETER_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_DIAMETER_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_4)
	{
		if (c == ' ')
			return (CY_SPACE_4);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	else if (state == CY_HEIGHT_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (c == '.')
			return (CY_HEIGHT_DECIMAL);
		if (ft_isdigit(c))
			return (CY_HEIGHT_BEFORE_DECIMAL);
	}
	else if (state == CY_HEIGHT_DECIMAL)
	{
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_HEIGHT_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_HEIGHT_AFTER_DECIMAL);
	}
	else if (state == CY_SPACE_5)
	{
		if (c == ' ')
			return (CY_SPACE_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	else if (state == CY_RED)
	{
		if (c == ',')
			return (CY_COMMA_5);
		if (ft_isdigit(c))
			return (CY_RED);
	}
	else if (state == CY_COMMA_5)
	{
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_GREEN)
	{
		if (c == ',')
			return (CY_COMMA_6);
		if (ft_isdigit(c))
			return (CY_GREEN);
	}
	else if (state == CY_COMMA_6)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
	}
	else if (state == CY_BLUE)
	{
		if (ft_isdigit(c))
			return (CY_BLUE);
		if (c == '\n')
			return (CY_ACCEPT);
		if (c == ' ')
			return (CY_SPACE_6);
	}
	else if (state == CY_SPACE_6)
	{
		if (c == ' ')
			return (CY_SPACE_6);
		if (c == '\n')
			return (CY_ACCEPT);
	}
	else if (state == CY_ACCEPT)
		return (CY_ACCEPT);
	return (CY_REJECT);
}

int	is_valid_cylinder(char *line)
{
	t_cy_state	state;
	int			i;

	i = 0;
	state = CY_START;
	while (line[i])
	{
		state = cylinder_transition(state, line[i]);
		if (state == CY_REJECT)
			break ;
		i++;
	}
	if (state == CY_ACCEPT || state == CY_BLUE || state == CY_SPACE_6)
		return (1);
	ft_putstr_fd("Error\nCylinder could not be parsed\n", STDERR_FILENO);
	return (0);
}
