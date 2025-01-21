/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/21 22:49:05 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "libft.h"

void insertion_sort(t_dlist **a, t_dlist **b, int *ops)
{
    while (*a)
    {
        while (*a != get_lst_min(*a, false))
            rotate(a, ops); 
        push_first(a, b, ops);
    }
    while (*b)
        push_first(b, a, ops);
}

int	get_min_dir(t_dlist *lst)
{
	int		len;
	int		i;
	t_dlist	*min;

	len = ft_dlstsize(lst);
	i = 0;
	min = get_lst_min(lst, false);
	while (lst)
	{
		if (lst == min)
			break;
		i++;
		lst = lst->next;
	}
	return (i <= len / 2);
}

void	dir_insertion_sort(t_dlist **a, t_dlist **b, int *ops)
{
	while (*a)
	{
		if (get_min_dir(*a))
		{
			while (*a != get_lst_min(*a, false))
				rotate(a, ops);
			push_first(a, b, ops);
		}
		else
		{
			while (*a != get_lst_min(*a, false))
				reverse(a, ops);
			push_first(a, b, ops);

		}
	}
	while (*b)
		push_first(b, a, ops);
}
