NAME			:= miniRT
NAMEBONUS		:= miniRT_bonus
CC				:= cc
RM		    	:= rm -f
FLAGS			:= 
DEBUG			:= -g

HEADDIR			:= ./includes/
HEADLIST		:= miniRT.h \
					ambient_light.h \
					camera.h \
					colors.h \
					cylinder.h \
					function_tests.h \
					image.h \
					light.h \
					linked_list.h \
					matrix.h \
					plane.h \
					random.h \
					ray.h \
					sphere.h \
					vector.h

HEADERS			:= $(addprefix ${HEADDIR}, ${HEADLIST})

SRCSDIR			:= ./src/
SRCSLIST		:= main.c \
					ambient_light.c \
					camera.c \
					closest_hit.c \
					colors_clac.c \
					colors.c \
					cylinder.c \
					cylinder_intersect.c \
					cylinder_normal.c \
					data.c \
					diffuse_light.c \
					fill_scene.c \
					follow_ray.c \
					free.c \
					ft_atof.c \
					function_tests.c \
					hooks_obj_actions.c \
					hooks_resize_obj1.c \
					hooks_resize_obj2.c \
					hooks_rotate_obj1.c \
					hooks_rotate_obj2.c \
					hooks_translate_obj1.c \
					hooks_translate_obj2.c \
					hooks_scene_actions.c \
					hooks.c \
					light.c \
					light_angle_obj.c \
					linked_list1.c \
					linked_list2.c \
					malloc_safe.c \
					math_helper.c \
					matrix_operations.c \
					matrix.c \
					plane.c \
					rays.c \
					random.c \
					read_file.c \
					render_plane.c \
					render.c \
					scene.c \
					specular_light_helper.c \
					specular_light.c \
					sphere.c \
					validate_ambient_light.c \
					validate_arguments.c \
					validate_camera.c \
					validate_cylinder.c \
					validate_light.c \
					validate_numbers.c \
					validate_plane.c \
					validate_scene.c \
					validate_sphere.c \
					vector_helpers.c \
					vector_operations1.c \
					vector_operations2.c \
					
SRCS			:= $(addprefix ${SRCSDIR}, ${SRCSLIST})

SRCSLISTBONUS	:= render_status_bonus.c
SRCSBONUS		:= $(addprefix ${SRCSDIR}, ${SRCSLISTBONUS})

OBJSDIR			:= ./obj/
OBJSLIST		:= ${SRCSLIST:.c=.o}
OBJS			:= $(addprefix ${OBJSDIR}, ${OBJSLIST})

OBJSLISTBONUS 	:= ${OBJSLIST} ${SRCSLISTBONUS:.c=.o}
OBJSBONUS		:= $(addprefix ${OBJSDIR}, ${OBJSLISTBONUS})

MLXDIR			:= ./minilibx-linux/
MLX				:= ${MLXDIR}libmlx.a

LIBFTDIR		:= ./libft/
LIBFT			:= ${LIBFTDIR}libft.a

LIBS			:= -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -lX11 -lm
INCS			:= -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}

CYAN			:= \033[0;36m
RESET			:= \033[0m

${NAME}:		${MLX} ${LIBFT} ${OBJSDIR} ${OBJS}
				@echo ""
				@echo "${CYAN}Compiling ${NAME} ...${RESET}"
				${CC} ${FLAGS} ${DEBUG} ${OBJS} -o ${NAME} ${LIBS} ${INCS}
				@echo ""
				@echo "${CYAN}${NAME} Created${RESET}"

${NAMEBONUS}:	${MLX} ${LIBFT} ${OBJSDIR} ${OBJSBONUS}
				@echo ""
				@echo "${CYAN}Compiling ${NAMEBONUS} ...${RESET}"
				${CC} ${FLAGS} ${DEBUG} ${OBJSBONUS} -o ${NAMEBONUS} ${LIBS} ${INCS}
				@echo ""
				@echo "${CYAN}${NAME} Created${RESET}"
${MLX}:
				@echo ""
				@echo "${CYAN}Compiling ${MLX} ...${RESET}"
				git submodule init
				git submodule update
				make -C ${MLXDIR}

${LIBFT}:
				make -C ${LIBFTDIR}

${OBJSDIR}%.o:	${SRCSDIR}%.c ${HEADERS} compiling
				${CC} ${FLAGS} ${DEBUG} ${INCS} -c $< -o $@

${OBJSDIR}:
				mkdir -p ${OBJSDIR}

.PHONY:			all clean fclean re test 

.INTERMEDIATE:	compiling

compiling:
				@echo ""
				@echo "${CYAN}Compiling Objects ...${RESET}"

all:			${NAME}

bonus:			${NAMEBONUS}

clean:
				@echo ""
				@echo "${CYAN}Deleting ${NAME}/${NAMEBONUS} Objects ...${RESET}"
				${RM} -r ${OBJSDIR}
				make -C ${LIBFTDIR} clean

fclean:			clean
				@echo ""
				@echo "${CYAN}Deleting ${NAME}/${NAMEBONUS} Executable ...${RESET}"
				${RM} ${NAME} ${NAMEBONUS}
				make -C ${LIBFTDIR} fclean

re:				fclean all

test:			all
				./${NAME} scenes/reflectiontest1.rt

val:			all
				valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				./${NAME} scenes/dummy_scene.rt
