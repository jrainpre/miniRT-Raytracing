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

typedef enum e_line_state
{
	LINE_START,
	LINE_AMBIENT_LIGHT,
	LINE_CAMERA,
	LINE_LIGHT,
	LINE_SPHERE,
	LINE_PLANE,
	LINE_CYLINDER,
	LINE_NEW_LINE,
	LINE_ACCEPT,
	LINE_REJECT
}	t_line_state;

int			is_valid_scene(char **scene_arr);
int			is_valid_ambient_light(char *line);
int			is_valid_camera(char *line);
int			is_valid_cylinder(char *line);
int			is_valid_light(char *line);
int			is_valid_plane(char *line);
int			is_valid_sphere(char *line);
t_a_state	ambient_light_transition(t_a_state state, char c);

#endif