#ifndef DETERMINISTIC_FINITE_AUTOMATON_H
# define DETERMINISTIC_FINITE_AUTOMATON_H

typedef enum e_a_state
{
	A_START,
	A_IDENTIFIER,
	A_SPACE_1,
	A_LIGHT_RATIO_BEFORE_DECIMAL,
	A_LIGHT_RATIO_DECIMAL,
	A_LIGHT_RATIO_AFTER_DECIMAL,
	A_SPACE_2,
	A_RED,
	A_COMMA_1,
	A_GREEN,
	A_COMMA_2,
	A_BLUE,
	A_SPACE_3,
	A_ACCEPT,
	A_REJECT
}	t_a_state;

int			is_valid_ambient_light(char *line);
t_a_state	ambient_light_transition(t_a_state state, char c);

#endif