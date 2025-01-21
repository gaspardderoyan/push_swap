/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:19:07 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 00:19:09 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

void swap_first(t_dlist **lst, int *ops)
{
	void *temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = temp;
	if (ops)
		(*ops)++;
}

void    f_both(t_dlist **a, t_dlist **b, void (f)(t_dlist**), int *ops)
{
	f(a);
	f(b);
	if (ops)
		*ops += 2;
}

void    push_first(t_dlist **in, t_dlist **out, int *ops)
{
	t_dlist *temp;

	if (!in || !*in || !(*in)->content)
		return ;

	temp = *in;
	*in = (*in)->next;
	temp->next = NULL;
	ft_dlstadd_front(out, temp);
	if (ops)
		(*ops)++;
}

void   rotate(t_dlist **lst, int *ops)
{
	t_dlist *temp;

	if (ft_dlstsize(*lst) <= 1)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
    (*lst)->prev = NULL; // New head has no previous node
	temp->next = NULL;
	ft_dlstadd_back(lst, temp);
	if (ops)
		(*ops)++;
}

void    reverse(t_dlist **lst, int *ops)
{
	t_dlist *next_to_last;
	t_dlist *last;

	if (ft_dlstsize(*lst) <= 1)
		return ;
	last = ft_dlstlast(*lst);
	next_to_last = last->prev;
	next_to_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if (ops)
		(*ops)++;
}
