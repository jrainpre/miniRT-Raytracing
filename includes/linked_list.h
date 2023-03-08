#ifndef LINEKED_LIST_H
# define LINEKED_LIST_H

# include <stdlib.h>

typedef struct s_lst
{
	void			*content;
	struct s_lst	*prev;
	struct s_lst	*next;
}						t_lst;

typedef struct t_lst_ref
{
	t_lst	*head;
	t_lst	*last;
}						t_lst_ref;

t_lst					*ft_lstlast(t_lst *lst);
t_lst					*ft_lstnew(void *content);
void					ft_add_lst_head(t_lst *new_entry, t_lst_ref *lst_ref);
void					ft_add_lst_last(t_lst *new_entry, t_lst_ref *lst_ref);
void					free_lst(t_lst_ref *lst_ref);
int						lstsize(t_lst *lst);

#endif



