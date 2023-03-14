#include "miniRT.h"

/*
Deterministic Finite Automaton:
https://automatonsimulator.com/#%7B%22type%22%3A%22DFA%22%2C%22dfa%22%3A%7B%22transitions%22%3A%7B%22start%22%3A%7B%22%20%22%3A%22start%22%2C%22A%22%3A%22s0%22%2C%22x%22%3A%22s2%22%7D%2C%22s0%22%3A%7B%22%20%22%3A%22s1%22%2C%22x%22%3A%22s2%22%7D%2C%22s1%22%3A%7B%220%22%3A%22s3%22%2C%22%20%22%3A%22s1%22%2C%22x%22%3A%22s2%22%7D%2C%22s3%22%3A%7B%220%22%3A%22s3%22%2C%22.%22%3A%22s5%22%2C%22%20%22%3A%22s6%22%2C%22x%22%3A%22s2%22%7D%2C%22s5%22%3A%7B%220%22%3A%22s8%22%2C%22x%22%3A%22s2%22%7D%2C%22s8%22%3A%7B%220%22%3A%22s8%22%2C%22x%22%3A%22s2%22%2C%22%20%22%3A%22s6%22%7D%2C%22s6%22%3A%7B%220%22%3A%22s9%22%2C%22%20%22%3A%22s6%22%2C%22x%22%3A%22s2%22%7D%2C%22s9%22%3A%7B%220%22%3A%22s9%22%2C%22%2C%22%3A%22s10%22%2C%22x%22%3A%22s2%22%7D%2C%22s10%22%3A%7B%220%22%3A%22s4%22%2C%22x%22%3A%22s2%22%7D%2C%22s4%22%3A%7B%220%22%3A%22s4%22%2C%22x%22%3A%22s2%22%2C%22%2C%22%3A%22s11%22%7D%2C%22s11%22%3A%7B%220%22%3A%22s7%22%2C%22x%22%3A%22s2%22%7D%2C%22s7%22%3A%7B%220%22%3A%22s7%22%2C%22x%22%3A%22s2%22%2C%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%7D%2C%22s13%22%3A%7B%22%20%22%3A%22s13%22%2C%22n%22%3A%22s12%22%2C%22x%22%3A%22s2%22%7D%7D%2C%22startState%22%3A%22start%22%2C%22acceptStates%22%3A%5B%22s12%22%5D%7D%2C%22states%22%3A%7B%22start%22%3A%7B%7D%2C%22s0%22%3A%7B%22top%22%3A332%2C%22left%22%3A60%2C%22displayId%22%3A%22A_IDENTIFIER%22%7D%2C%22s2%22%3A%7B%22top%22%3A209%2C%22left%22%3A246%2C%22displayId%22%3A%22A_REJECT%22%7D%2C%22s1%22%3A%7B%22top%22%3A330%2C%22left%22%3A271%2C%22displayId%22%3A%22A_SPACE_1%22%7D%2C%22s3%22%3A%7B%22top%22%3A480%2C%22left%22%3A31%2C%22displayId%22%3A%22A_LIGHT_RATIO_BEFORE_DECIMAL%22%7D%2C%22s5%22%3A%7B%22top%22%3A487%2C%22left%22%3A432%2C%22displayId%22%3A%22A_LIGHT_RATIO_DECIMAL%22%7D%2C%22s6%22%3A%7B%22top%22%3A327%2C%22left%22%3A830%2C%22displayId%22%3A%22A_SPACE_2%22%7D%2C%22s8%22%3A%7B%22top%22%3A479%2C%22left%22%3A800%2C%22displayId%22%3A%22A_LIGHT_RATIO_AFTER_DECIMAL%22%7D%2C%22s9%22%3A%7B%22top%22%3A325%2C%22left%22%3A1041%2C%22displayId%22%3A%22A_RED%22%7D%2C%22s10%22%3A%7B%22top%22%3A260%2C%22left%22%3A1201%2C%22displayId%22%3A%22A_COMMA_1%22%7D%2C%22s4%22%3A%7B%22top%22%3A170%2C%22left%22%3A1222%2C%22displayId%22%3A%22A_GREEN%22%7D%2C%22s11%22%3A%7B%22top%22%3A122%2C%22left%22%3A1050%2C%22displayId%22%3A%22A_COMMA_2%22%7D%2C%22s7%22%3A%7B%22top%22%3A65%2C%22left%22%3A973%2C%22displayId%22%3A%22A_BLUE%22%7D%2C%22s13%22%3A%7B%22top%22%3A86%2C%22left%22%3A437%2C%22displayId%22%3A%22A_SPACE_3%22%7D%2C%22s12%22%3A%7B%22isAccept%22%3Atrue%2C%22top%22%3A24%2C%22left%22%3A142%2C%22displayId%22%3A%22A_ACCEPT%22%7D%7D%2C%22transitions%22%3A%5B%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22start%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22A%22%2C%22stateB%22%3A%22s0%22%7D%2C%7B%22stateA%22%3A%22start%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s0%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s0%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s1%22%7D%2C%7B%22stateA%22%3A%22s1%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s3%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22.%22%2C%22stateB%22%3A%22s5%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s3%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s5%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s5%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s8%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s8%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s6%22%7D%2C%7B%22stateA%22%3A%22s6%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s9%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s10%22%7D%2C%7B%22stateA%22%3A%22s9%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s10%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s10%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s4%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s4%22%2C%22label%22%3A%22%2C%22%2C%22stateB%22%3A%22s11%22%7D%2C%7B%22stateA%22%3A%22s11%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s11%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%220%22%2C%22stateB%22%3A%22s7%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s7%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22%20%22%2C%22stateB%22%3A%22s13%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22n%22%2C%22stateB%22%3A%22s12%22%7D%2C%7B%22stateA%22%3A%22s13%22%2C%22label%22%3A%22x%22%2C%22stateB%22%3A%22s2%22%7D%5D%2C%22bulkTests%22%3A%7B%22accept%22%3A%22%20%20%20%20A%200.0%20%20000%2C000%2C000%20%20%20n%5Cn%20%20%20A%20%200%200%2C0%2C00n%22%2C%22reject%22%3A%22%22%7D%7D
*/

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
	if (state == A_ACCEPT)
		return (1);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}
