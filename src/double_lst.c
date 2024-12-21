#include "double_lst.h"

t_dlist *ft_dlstnew(void *content)
{
	t_dlist	*head;

	head = (t_dlist *)malloc(sizeof(t_dlist));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void    ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
    if (!new)
        return ;
    if (!*lst)
        *lst = new;
    else
    {
        new->next = *lst;
        (*lst)->prev = new;
        *lst = new;
    }
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*cursor;

	if (lst == NULL)
		return (NULL);
	cursor = lst;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_dlstlast(*lst);
		if (last)
        {
			last->next = new;
            new->prev = last;
        }
	}
}