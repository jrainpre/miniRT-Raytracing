#include "miniRT.h"

t_l_state	light_transition(t_l_state state, char c)
{
	if (state == L_START)
	{
		if (c == ' ')
			return (L_START);
		if (c == 'L')
			return (L_IDENTIFIER_1);
	}
	else if (state == L_IDENTIFIER_1)
	{
		if (c == ' ')
			return (L_SPACE_1);
	}
	else if (state == L_SPACE_1)
	{
		if (c == ' ')
			return (L_SPACE_1);
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_X_SIGN);
	}
	else if (state == L_ORIG_X_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_X_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_1);
		if (c == '.')
			return (L_ORIG_X_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_X_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_X_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == L_ORIG_X_AFTER_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_1);
		if (ft_isdigit(c))
			return (L_ORIG_X_AFTER_DECIMAL);
	}
	else if (state == L_COMMA_1)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_Y_SIGN);
	}
	else if (state == L_ORIG_Y_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Y_BEFORE_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_2);
		if (c == '.')
			return (L_ORIG_Y_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_Y_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Y_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == L_ORIG_Y_AFTER_DECIMAL)
	{
		if (c == ',')
			return (L_COMMA_2);
		if (ft_isdigit(c))
			return (L_ORIG_Y_AFTER_DECIMAL);
	}
	else if (state == L_COMMA_2)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
		if (c == '-' || c == '+')
			return (L_ORIG_Z_SIGN);
	}
	else if (state == L_ORIG_Z_SIGN)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Z_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (c == '.')
			return (L_ORIG_Z_DECIMAL);
		if (ft_isdigit(c))
			return (L_ORIG_Z_BEFORE_DECIMAL);
	}
	else if (state == L_ORIG_Z_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == L_ORIG_Z_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (ft_isdigit(c))
			return (L_ORIG_Z_AFTER_DECIMAL);
	}
	else if (state == L_SPACE_2)
	{
		if (c == ' ')
			return (L_SPACE_2);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_BEFORE_DECIMAL);
	}
	else if (state == L_BRIGHTNESS_BEFORE_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (c == '.')
			return (L_BRIGHTNESS_DECIMAL);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_BEFORE_DECIMAL);
	}
	else if (state == L_BRIGHTNESS_DECIMAL)
	{
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_AFTER_DECIMAL);
	}
	else if (state == L_BRIGHTNESS_AFTER_DECIMAL)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (ft_isdigit(c))
			return (L_BRIGHTNESS_AFTER_DECIMAL);
	}
	else if (state == L_SPACE_3)
	{
		if (c == ' ')
			return (L_SPACE_3);
		if (ft_isdigit(c))
			return (L_RED);
	}
	else if (state == L_RED)
	{
		if (c == ',')
			return (L_COMMA_3);
		if (ft_isdigit(c))
			return (L_RED);
	}
	else if (state == L_COMMA_3)
	{
		if (ft_isdigit(c))
			return (L_GREEN);
	}
	else if (state == L_GREEN)
	{
		if (c == ',')
			return (L_COMMA_4);
		if (ft_isdigit(c))
			return (L_GREEN);
	}
	else if (state == L_COMMA_4)
	{
		if (ft_isdigit(c))
			return (L_BLUE);
	}
	else if (state == L_BLUE)
	{
		if (ft_isdigit(c))
			return (L_BLUE);
		if (c == '\n')
			return (L_ACCEPT);
		if (c == ' ')
			return (L_SPACE_4);
	}
	else if (state == L_SPACE_4)
	{
		if (c == ' ')
			return (L_SPACE_4);
		if (c == '\n')
			return (L_ACCEPT);
	}
	else if (state == L_ACCEPT)
		return (L_ACCEPT);
	return (L_REJECT);
}

int	is_valid_light(char *line)
{
	t_l_state	state;
	int			i;

	i = 0;
	state = L_START;
	while (line[i])
	{
		state = light_transition(state, line[i]);
		if (state == L_REJECT)
			break ;
		i++;
	}
	if (state == L_ACCEPT || state == L_SPACE_4 || state == L_BLUE)
		return (1);
	ft_putstr_fd("Error\nLight could not be parsed\n", STDERR_FILENO);
	return (0);
}
