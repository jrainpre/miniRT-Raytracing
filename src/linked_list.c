
#include "linked_list.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new_lst;

	new_lst = (t_lst *)malloc(sizeof(t_lst));
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	ft_add_lst_last(t_lst *new_entry, t_lst_ref *lst_ref)
{
	t_lst	*prevlast;

	if (lst_ref->head == NULL)
	{
		lst_ref->head = new_entry;
		lst_ref->last = new_entry;
	}
	else if (lst_ref->last)
	{
		prevlast = ft_lstlast(lst_ref->head);
		prevlast->next = new_entry;
		new_entry->prev = prevlast;
		lst_ref->last = new_entry;
	}
}

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

void	free_lst(t_lst_ref *lst_ref)
{
	int	i;
	t_lst *temp;
	t_lst *next;

	i = 0;
	temp = lst_ref->head;
	while (temp != NULL)
	{
		free(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
		i++;
	}
}
