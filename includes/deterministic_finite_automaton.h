/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deterministic_finite_automaton.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <frafal@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:03:21 by frafal            #+#    #+#             */
/*   Updated: 2023/05/16 13:17:19 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETERMINISTIC_FINITE_AUTOMATON_H
# define DETERMINISTIC_FINITE_AUTOMATON_H

# include "linked_list.h"

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

typedef enum e_l_state
{
	L_START,
	L_IDENTIFIER_1,
	L_SPACE_1,
	L_ORIG_X_SIGN,
	L_ORIG_X_BEFORE_DECIMAL,
	L_ORIG_X_DECIMAL,
	L_ORIG_X_AFTER_DECIMAL,
	L_COMMA_1,
	L_ORIG_Y_SIGN,
	L_ORIG_Y_BEFORE_DECIMAL,
	L_ORIG_Y_DECIMAL,
	L_ORIG_Y_AFTER_DECIMAL,
	L_COMMA_2,
	L_ORIG_Z_SIGN,
	L_ORIG_Z_BEFORE_DECIMAL,
	L_ORIG_Z_DECIMAL,
	L_ORIG_Z_AFTER_DECIMAL,
	L_SPACE_2,
	L_BRIGHTNESS_BEFORE_DECIMAL,
	L_BRIGHTNESS_DECIMAL,
	L_BRIGHTNESS_AFTER_DECIMAL,
	L_SPACE_3,
	L_RED,
	L_COMMA_3,
	L_GREEN,
	L_COMMA_4,
	L_BLUE,
	L_SPACE_4,
	L_ACCEPT,
	L_REJECT
}	t_l_state;

typedef enum e_c_state
{
	C_START,
	C_IDENTIFIER_1,
	C_SPACE_1,
	C_ORIG_X_SIGN,
	C_ORIG_X_BEFORE_DECIMAL,
	C_ORIG_X_DECIMAL,
	C_ORIG_X_AFTER_DECIMAL,
	C_COMMA_1,
	C_ORIG_Y_SIGN,
	C_ORIG_Y_BEFORE_DECIMAL,
	C_ORIG_Y_DECIMAL,
	C_ORIG_Y_AFTER_DECIMAL,
	C_COMMA_2,
	C_ORIG_Z_SIGN,
	C_ORIG_Z_BEFORE_DECIMAL,
	C_ORIG_Z_DECIMAL,
	C_ORIG_Z_AFTER_DECIMAL,
	C_SPACE_2,
	C_ORIENTATION_X_SIGN,
	C_ORIENTATION_X_BEFORE_DECIMAL,
	C_ORIENTATION_X_DECIMAL,
	C_ORIENTATION_X_AFTER_DECIMAL,
	C_COMMA_3,
	C_ORIENTATION_Y_SIGN,
	C_ORIENTATION_Y_BEFORE_DECIMAL,
	C_ORIENTATION_Y_DECIMAL,
	C_ORIENTATION_Y_AFTER_DECIMAL,
	C_COMMA_4,
	C_ORIENTATION_Z_SIGN,
	C_ORIENTATION_Z_BEFORE_DECIMAL,
	C_ORIENTATION_Z_DECIMAL,
	C_ORIENTATION_Z_AFTER_DECIMAL,
	C_SPACE_3,
	C_FOV_BEFORE_DECIMAL,
	C_FOV_DECIMAL,
	C_FOV_AFTER_DECIMAL,
	C_SPACE_4,
	C_ACCEPT,
	C_REJECT
}	t_c_state;

typedef enum e_s_state
{
	S_START,
	S_IDENTIFIER_1,
	S_IDENTIFIER_2,
	S_SPACE_1,
	S_ORIG_X_SIGN,
	S_ORIG_X_BEFORE_DECIMAL,
	S_ORIG_X_DECIMAL,
	S_ORIG_X_AFTER_DECIMAL,
	S_COMMA_1,
	S_ORIG_Y_SIGN,
	S_ORIG_Y_BEFORE_DECIMAL,
	S_ORIG_Y_DECIMAL,
	S_ORIG_Y_AFTER_DECIMAL,
	S_COMMA_2,
	S_ORIG_Z_SIGN,
	S_ORIG_Z_BEFORE_DECIMAL,
	S_ORIG_Z_DECIMAL,
	S_ORIG_Z_AFTER_DECIMAL,
	S_SPACE_2,
	S_DIAMETER_BEFORE_DECIMAL,
	S_DIAMETER_DECIMAL,
	S_DIAMETER_AFTER_DECIMAL,
	S_SPACE_3,
	S_RED,
	S_COMMA_3,
	S_GREEN,
	S_COMMA_4,
	S_BLUE,
	S_SPACE_4,
	S_SPACE_5,
	S_REFLECTIVENESS_BEFORE_DECIMAL,
	S_REFLECTIVENESS_DECIMAL,
	S_REFLECTIVENESS_AFTER_DECIMAL,
	S_ACCEPT,
	S_REJECT
}	t_s_state;

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

typedef enum e_p_state
{
	P_START,
	P_IDENTIFIER_1,
	P_IDENTIFIER_2,
	P_SPACE_1,
	P_ORIG_X_SIGN,
	P_ORIG_X_BEFORE_DECIMAL,
	P_ORIG_X_DECIMAL,
	P_ORIG_X_AFTER_DECIMAL,
	P_COMMA_1,
	P_ORIG_Y_SIGN,
	P_ORIG_Y_BEFORE_DECIMAL,
	P_ORIG_Y_DECIMAL,
	P_ORIG_Y_AFTER_DECIMAL,
	P_COMMA_2,
	P_ORIG_Z_SIGN,
	P_ORIG_Z_BEFORE_DECIMAL,
	P_ORIG_Z_DECIMAL,
	P_ORIG_Z_AFTER_DECIMAL,
	P_SPACE_2,
	P_NORMAL_X_SIGN,
	P_NORMAL_X_BEFORE_DECIMAL,
	P_NORMAL_X_DECIMAL,
	P_NORMAL_X_AFTER_DECIMAL,
	P_COMMA_3,
	P_NORMAL_Y_SIGN,
	P_NORMAL_Y_BEFORE_DECIMAL,
	P_NORMAL_Y_DECIMAL,
	P_NORMAL_Y_AFTER_DECIMAL,
	P_COMMA_4,
	P_NORMAL_Z_SIGN,
	P_NORMAL_Z_BEFORE_DECIMAL,
	P_NORMAL_Z_DECIMAL,
	P_NORMAL_Z_AFTER_DECIMAL,
	P_SPACE_3,
	P_RED,
	P_COMMA_5,
	P_GREEN,
	P_COMMA_6,
	P_BLUE,
	P_SPACE_4,
	P_SPACE_5,
	P_REFLECTIVENESS_BEFORE_DECIMAL,
	P_REFLECTIVENESS_DECIMAL,
	P_REFLECTIVENESS_AFTER_DECIMAL,
	P_ACCEPT,
	P_REJECT
}	t_p_state;

typedef enum e_cy_state
{
	CY_START,
	CY_IDENTIFIER_1,
	CY_IDENTIFIER_2,
	CY_SPACE_1,
	CY_ORIG_X_SIGN,
	CY_ORIG_X_BEFORE_DECIMAL,
	CY_ORIG_X_DECIMAL,
	CY_ORIG_X_AFTER_DECIMAL,
	CY_COMMA_1,
	CY_ORIG_Y_SIGN,
	CY_ORIG_Y_BEFORE_DECIMAL,
	CY_ORIG_Y_DECIMAL,
	CY_ORIG_Y_AFTER_DECIMAL,
	CY_COMMA_2,
	CY_ORIG_Z_SIGN,
	CY_ORIG_Z_BEFORE_DECIMAL,
	CY_ORIG_Z_DECIMAL,
	CY_ORIG_Z_AFTER_DECIMAL,
	CY_SPACE_2,
	CY_AXIS_X_SIGN,
	CY_AXIS_X_BEFORE_DECIMAL,
	CY_AXIS_X_DECIMAL,
	CY_AXIS_X_AFTER_DECIMAL,
	CY_COMMA_3,
	CY_AXIS_Y_SIGN,
	CY_AXIS_Y_BEFORE_DECIMAL,
	CY_AXIS_Y_DECIMAL,
	CY_AXIS_Y_AFTER_DECIMAL,
	CY_COMMA_4,
	CY_AXIS_Z_SIGN,
	CY_AXIS_Z_BEFORE_DECIMAL,
	CY_AXIS_Z_DECIMAL,
	CY_AXIS_Z_AFTER_DECIMAL,
	CY_SPACE_3,
	CY_DIAMETER_BEFORE_DECIMAL,
	CY_DIAMETER_DECIMAL,
	CY_DIAMETER_AFTER_DECIMAL,
	CY_SPACE_4,
	CY_HEIGHT_BEFORE_DECIMAL,
	CY_HEIGHT_DECIMAL,
	CY_HEIGHT_AFTER_DECIMAL,
	CY_SPACE_5,
	CY_RED,
	CY_COMMA_5,
	CY_GREEN,
	CY_COMMA_6,
	CY_BLUE,
	CY_SPACE_6,
	CY_SPACE_7,
	CY_REFLECTIVENESS_BEFORE_DECIMAL,
	CY_REFLECTIVENESS_DECIMAL,
	CY_REFLECTIVENESS_AFTER_DECIMAL,
	CY_ACCEPT,
	CY_REJECT
}	t_cy_state;

int			is_valid_scene(t_lst_ref *scene_lines);
int			is_valid_ambient_light(char *line);
int			is_valid_camera(char *line);
int			is_valid_cylinder(char *line);
int			is_valid_light(char *line);
int			is_valid_plane(char *line);
int			is_valid_sphere(char *line);
int			is_valid_light(char *line);
t_a_state	ambient_light_transition(t_a_state state, char c);
t_a_state	ambient_light_transition_1(t_a_state state, char c);
t_a_state	ambient_light_transition_2(t_a_state state, char c);
t_a_state	ambient_light_transition_3(t_a_state state, char c);
t_a_state	ambient_light_transition_4(t_a_state state, char c);
t_c_state	camera_transition(t_c_state state, char c);
t_c_state	camera_transition_1(t_c_state state, char c);
t_c_state	camera_transition_2(t_c_state state, char c);
t_c_state	camera_transition_3(t_c_state state, char c);
t_c_state	camera_transition_4(t_c_state state, char c);
t_c_state	camera_transition_5(t_c_state state, char c);
t_c_state	camera_transition_6(t_c_state state, char c);
t_c_state	camera_transition_7(t_c_state state, char c);
t_c_state	camera_transition_8(t_c_state state, char c);
t_c_state	camera_transition_9(t_c_state state, char c);
t_c_state	camera_transition_10(t_c_state state, char c);
t_c_state	camera_transition_11(t_c_state state, char c);
t_c_state	camera_transition_12(t_c_state state, char c);
t_cy_state	cylinder_transition(t_cy_state state, char c);
t_cy_state	cylinder_transition_1(t_cy_state state, char c);
t_cy_state	cylinder_transition_2(t_cy_state state, char c);
t_cy_state	cylinder_transition_3(t_cy_state state, char c);
t_cy_state	cylinder_transition_4(t_cy_state state, char c);
t_cy_state	cylinder_transition_5(t_cy_state state, char c);
t_cy_state	cylinder_transition_6(t_cy_state state, char c);
t_cy_state	cylinder_transition_7(t_cy_state state, char c);
t_cy_state	cylinder_transition_8(t_cy_state state, char c);
t_cy_state	cylinder_transition_9(t_cy_state state, char c);
t_cy_state	cylinder_transition_10(t_cy_state state, char c);
t_cy_state	cylinder_transition_11(t_cy_state state, char c);
t_cy_state	cylinder_transition_12(t_cy_state state, char c);
t_cy_state	cylinder_transition_13(t_cy_state state, char c);
t_cy_state	cylinder_transition_14(t_cy_state state, char c);
t_cy_state	cylinder_transition_15(t_cy_state state, char c);
t_cy_state	cylinder_transition_16(t_cy_state state, char c);
t_s_state	sphere_transition(t_s_state state, char c);
t_l_state	light_transition(t_l_state state, char c);
t_p_state	plane_transition(t_p_state state, char c);
t_l_state	light_transition(t_l_state state, char c);

#endif