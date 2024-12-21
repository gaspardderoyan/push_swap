#include "project.h"

void swap_first(t_dlist **lst)
{
	void *temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = temp;
}

void    f_both(t_dlist **a, t_dlist **b, void (f)(t_dlist**))
{
	f(a);
	f(b);
}

void    push_first(t_dlist **in, t_dlist **out)
{
	t_dlist *temp;

	if (!in || !*in || !(*in)->content)
		return ;

	temp = *in;
	*in = (*in)->next;
	temp->next = NULL;
	ft_dlstadd_front(out, temp);
}

void   rotate(t_dlist **lst)
{
	t_dlist *temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_dlstadd_back(lst, temp);
}

void    reverse(t_dlist **lst)
{
	t_dlist *next_to_last;
	t_dlist *last;

	last = ft_dlstlast(*lst);
	next_to_last = get_ntl(*lst);
	next_to_last->next = NULL;
	last->next = *lst;
	*lst = last;
}
