#include "miniRT.h"

void	ft_add_lst_head(t_lst *new_entry, t_lst_ref *lst_ref)
{
	if (lst_ref->head == NULL)
	{
		lst_ref->head = new_entry;
		lst_ref->last = new_entry;
	}
	else
	{
		lst_ref->head->prev = new_entry;
		new_entry->next = lst_ref->head;
		lst_ref->head = new_entry;
	}
}

void	clear_lst(t_lst_ref *lst_ref)
{
	t_lst	*current;
	t_lst	*next;

	if (lst_ref != NULL)
	{
		current = lst_ref->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

void	*free_lst_null(t_lst_ref *lst_ref)
{
	int		i;
	t_lst	*temp;
	t_lst	*next;

	i = 0;
	temp = lst_ref->head;
	while (temp != NULL)
	{
		temp->content = free_null(temp->content);
		next = temp->next;
		temp = free_null(temp);
		temp = next;
		i++;
	}
	lst_ref = free_null(lst_ref);
	return (lst_ref);
}
