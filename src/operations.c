/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:19:07 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 17:50:22 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

void	swap_first(t_dlist **lst, t_dlist **l_ops, char *op_name)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = (*lst);
	second = (*lst)->next;
	(*lst) = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	ft_dlstadd_back(l_ops, ft_dlstnew(strdup_safe(op_name)));
}

void	f_both(t_mst *mst, void (f)(t_dlist**), char *op_name)
{
	f(&mst->a);
	f(&mst->b);
	ft_dlstadd_back(&mst->l_ops, ft_dlstnew(strdup_safe(op_name)));
}

void	push_first(t_dlist **in, t_dlist **out, t_dlist **l_ops, char *op_name)
{
	t_dlist	*temp;

	if (!in || !*in || !(*in)->content)
		return ;
	temp = *in;
	*in = (*in)->next;
	temp->next = NULL;
	temp->prev = NULL;
	ft_dlstadd_front(out, temp);
	ft_dlstadd_back(l_ops, ft_dlstnew(strdup_safe(op_name)));
}

void	rotate(t_dlist **lst, t_dlist **l_ops, char *op_name)
{
	t_dlist	*temp;

	if (ft_dlstsize(*lst) <= 1)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	temp->next = NULL;
	ft_dlstadd_back(lst, temp);
	ft_dlstadd_back(l_ops, ft_dlstnew(strdup_safe(op_name)));
}

void	reverse(t_dlist **lst, t_dlist **l_ops, char *op_name)
{
	t_dlist	*next_to_last;
	t_dlist	*last;

	if (ft_dlstsize(*lst) <= 1)
		return ;
	last = ft_dlstlast(*lst);
	next_to_last = last->prev;
	next_to_last->next = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
	(*lst)->prev = NULL;
	ft_dlstadd_back(l_ops, ft_dlstnew(strdup_safe(op_name)));
}
