#include "miniRT.h"

/*
Deterministic Finite Automaton:
https://automatonsimulator.com/#%7B%22type%22%3A%22DFA%22%2C%22dfa%22%3A%7B%22transitions%22%3A%7B%22start%22%3A%7B%22%20%22%3A%22start%22%2C%22s%22%3A%22s0%22%7D%2C%22s0%22%3A%7B%22p%22%3A%22s14%22%7D%2C%22s1%22%3A%7B%220%22%3A%22s3%22%2C%22%20%22%3A%22s1%22%7D%2C%22s3%22%3A%7B%220%22%3A%22s3%22%2C%22.%22%3A%22s5%22%2C%22%2C%22%3A%22s15%22%7D%2C%22s5%22%3A%7B%220%22%3A%22s8%22%7D%2C%22s8%22%3A%7B%220%22%3A%22s8%22%2C%22%2C%22%3A%22s15%22%7D%2C%22s6%22%3A%7B%220%22%3A%22s9%22%2C%22%20%22%3A%22s6%22%7D%2C%22s9%22%3A%7B%220%22%3A%22s9%22%2C%22%2C%22%3A%22s10%22%7D%2C%22s10%22%3A%7B%220%22%3A%22s4%22%7D%2C%22s4%22%3A%7B%220%22%3A%22s4%22%2C%22%2C%22%3A%22s11%22%7D%2C%22s11%22%3A%7B%220%22%3A%22s7%22%7D%2C%22s7%22%3A%7B%220%22%3A%22s7%22%2C%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%7D%2C%22s13%22%3A%7B%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%7D%2C%22s14%22%3A%7B%22%20%22%3A%22s1%22%7D%2C%22s15%22%3A%7B%220%22%3A%22s16%22%7D%2C%22s16%22%3A%7B%220%22%3A%22s16%22%2C%22.%22%3A%22s17%22%2C%22%2C%22%3A%22s19%22%7D%2C%22s17%22%3A%7B%220%22%3A%22s18%22%7D%2C%22s18%22%3A%7B%220%22%3A%22s18%22%2C%22%2C%22%3A%22s19%22%7D%2C%22s19%22%3A%7B%220%22%3A%22s20%22%7D%2C%22s20%22%3A%7B%220%22%3A%22s20%22%2C%22.%22%3A%22s21%22%2C%22%20%22%3A%22s23%22%7D%2C%22s21%22%3A%7B%220%22%3A%22s22%22%7D%2C%22s22%22%3A%7B%220%22%3A%22s22%22%2C%22%20%22%3A%22s23%22%7D%2C%22s23%22%3A%7B%220%22%3A%22s24%22%2C%22%20%22%3A%22s23%22%7D%2C%22s24%22%3A%7B%220%22%3A%22s24%22%2C%22.%22%3A%22s25%22%2C%22%20%22%3A%22s6%22%7D%2C%22s25%22%3A%7B%220%22%3A%22s26%22%7D%2C%22s26%22%3A%7B%220%22%3A%22s26%22%2C%22%20%22%3A%22s6%22%7D%7D%2C%22startState%22%3A%22start%22%2C%22acceptStates%22%3A%5B%22s12%22%5D%7D%2C%22states%22%3A%7B%22start%22%3A%7B%7D%2C%22s0%22%3A%7B%22top%22%3A435%2C%22left%22%3A-2045%2C%22displayId%22%3A%22S_IDENTIFIER_1%22%7D%2C%22s14%22%3A%7B%22top%22%3A515%2C%22left%22%3A-2045%2C%22displayId%22%3A%22S_IDENTIFIER_2%22%7D%2C%22s1%22%3A%7B%22top%22%3A66%2C%22left%22%3A-2014%2C%22displayId%22%3A%22S_SPACE_1%22%7D%2C%22s3%22%3A%7B%22top%22%3A71%2C%22left%22%3A-1824%2C%22displayId%22%3A%22S_ORIG_X_BEFORE_DECIMAL%22%7D%2C%22s5%22%3A%7B%22top%22%3A172%2C%22left%22%3A-1788%2C%22displayId%22%3A%22S_ORIG_X_DECIMAL%22%7D%2C%22s15%22%3A%7B%22top%22%3A175%2C%22left%22%3A-1532%2C%22displayId%22%3A%22S_COMMA_1%22%7D%2C%22s8%22%3A%7B%22top%22%3A302%2C%22left%22%3A-1805%2C%22displayId%22%3A%22S_ORIG_X_AFTER_DECIMAL%22%7D%2C%22s6%22%3A%7B%22top%22%3A183%2C%22left%22%3A-81%2C%22displayId%22%3A%22S_SPACE_3%22%7D%2C%22s9%22%3A%7B%22top%22%3A81%2C%22left%22%3A166%2C%22displayId%22%3A%22S_RED%22%7D%2C%22s10%22%3A%7B%22top%22%3A183%2C%22left%22%3A144%2C%22displayId%22%3A%22S_COMMA_3%22%7D%2C%22s4%22%3A%7B%22top%22%3A305%2C%22left%22%3A234%2C%22displayId%22%3A%22S_GREEN%22%7D%2C%22s11%22%3A%7B%22top%22%3A410%2C%22left%22%3A243%2C%22displayId%22%3A%22S_COMMA_4%22%7D%2C%22s7%22%3A%7B%22top%22%3A531%2C%22left%22%3A363%2C%22displayId%22%3A%22S_BLUE%22%7D%2C%22s13%22%3A%7B%22top%22%3A290%2C%22left%22%3A565%2C%22displayId%22%3A%22S_SPACE_4%22%7D%2C%22s12%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A532%2C%22left%22%3A605%2C%22displayId%22%3A%22S_ACCEPT%22%7D%2C%22s16%22%3A%7B%22top%22%3A72%2C%22left%22%3A-1329%2C%22displayId%22%3A%22S_ORIG_Y_BEFORE_DECIMAL%22%7D%2C%22s17%22%3A%7B%22top%22%3A166%2C%22left%22%3A-1316%2C%22displayId%22%3A%22S_ORIG_Y_DECIMAL%22%7D%2C%22s19%22%3A%7B%22top%22%3A169%2C%22left%22%3A-1065%2C%22displayId%22%3A%22S_COMMA_2%22%7D%2C%22s18%22%3A%7B%22top%22%3A299%2C%22left%22%3A-1321%2C%22displayId%22%3A%22S_ORIG_Y_AFTER_DECIMAL%22%7D%2C%22s20%22%3A%7B%22top%22%3A76%2C%22left%22%3A-837%2C%22displayId%22%3A%22S_ORIG_Z_BEFORE_DECIMAL%22%7D%2C%22s21%22%3A%7B%22top%22%3A183%2C%22left%22%3A-843%2C%22displayId%22%3A%22S_ORIG_Z_DECIMAL%22%7D%2C%22s23%22%3A%7B%22top%22%3A185%2C%22left%22%3A-574%2C%22displayId%22%3A%22S_SPACE_2%22%7D%2C%22s22%22%3A%7B%22top%22%3A310%2C%22left%22%3A-839%2C%22displayId%22%3A%22S_ORIG_Z_AFTER_DECIMAL%22%7D%2C%22s24%22%3A%7B%22top%22%3A77%2C%22left%22%3A-362%2C%22displayId%22%3A%22S_DIAMETER_BEFORE_DECIMAL%22%7D%2C%22s25%22%3A%7B%22top%22%3A183%2C%22left%22%3A-363%2C%22displayId%22%3A%22S_DIAMETER_DECIMAL%22%7D%2C%22s26%22%3A%7B%22top%22%3A312%2C%22left%22%3A-365%2C%22displayId%22%3A%22S_DIAMETER_AFTER_DECIMAL%22%7D%7D%2C%22transitions%22%3A%5B%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22start%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22s%22%2C%22stateB%22%3A%22s0%22%7D%2C%7B%22stateA%22%3A%22s0%22%2C%22label%22%3A%22p%22%2C%22stateB%22%3A%22s14%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s5%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s15%22%7D%2C%7B%22stateA%22%3A%22s5%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s15%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s10%22%7D%2C%7B%22stateA%22%3A%22s10%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s11%22%7D%2C%7B%22stateA%22%3A%22s11%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s14%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s15%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s16%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s16%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s17%22%7D%2C%7B%22stateA%22%3A%22s16%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s19%22%7D%2C%7B%22stateA%22%3A%22s17%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s18%22%7D%2C%7B%22stateA%22%3A%22s18%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s18%22%7D%2C%7B%22stateA%22%3A%22s18%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s19%22%7D%2C%7B%22stateA%22%3A%22s19%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s20%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s20%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s21%22%7D%2C%7B%22stateA%22%3A%22s20%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s21%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s22%22%7D%2C%7B%22stateA%22%3A%22s22%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s22%22%7D%2C%7B%22stateA%22%3A%22s22%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s23%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s24%22%7D%2C%7B%22stateA%22%3A%22s23%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s23%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s24%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s25%22%7D%2C%7B%22stateA%22%3A%22s24%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s25%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s26%22%7D%2C%7B%22stateA%22%3A%22s26%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s26%22%7D%2C%7B%22stateA%22%3A%22s26%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%5D%2C%22bulkTests%22%3A%7B%22accept%22%3A%22%22%2C%22reject%22%3A%22%22%7D%7D
*/

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
	if (state == S_ACCEPT)
		return (1);
	ft_putstr_fd("Error\nSphere could not be parsed\n", STDERR_FILENO);
	return (0);
}
