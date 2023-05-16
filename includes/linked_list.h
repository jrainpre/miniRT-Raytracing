#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef enum e_object_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	CAMERA,
	LIGHT,
	AMBIENT_LIGHT,
	NOT_VALID
}	t_object_type;
typedef struct s_lst
{
	void				*content;
	enum e_object_type	type;
	int 				is_slected;
	struct s_lst		*prev;
	struct s_lst		*next;
}						t_lst;

typedef struct s_lst_ref
{
	t_lst	*head;
	t_lst	*last;
}						t_lst_ref;

#endif




